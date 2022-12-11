#include "loadstore.hh"

Loadstore::Loadstore(char const* filename) { 
    cycles = 1;
    area = 20000;
    power = 4.0;

    for(int i = 0; i < 100; i++) {
        mem[i] = 0;
    }

    instructionFile.open(filename, std::ios::out | std::ios::binary);
    if(!instructionFile) {
      std::cout << "Cannot open instruction file" << std::endl;
    }

    //Read the instructions into the memory 
    int mem_index = 0;
    while (true) {
        instructionFile.read((char *) &mem[mem_index], sizeof(uint32_t));
        if (instructionFile.eof()) {
            break;
        }
        mem_index++;
    }

    if (mem[mem_index-1] != 4160749568) { // if the last instruction is not the halt instruction 
        mem[mem_index] = 4160749568; // add halt intruction
        mem_index++;
    }

    num_instructions = mem_index;
}

Loadstore::~Loadstore() {
    instructionFile.close();
}

void Loadstore::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }

    long long index = *inport[0] / 4; // *inport[0] is the address, /4 because each mem_unit is 4 bytes

    cycle_counter = 0;
    if (*ctrlport == 0) { // 0 to read
        if (index >= MEMORY_LENGTH) {
            throw std::runtime_error("READ outside of memory range.");
            return;
        }
        outport[0] = mem[index];
    }
    else if (*ctrlport == 1) { // 1 to write
        if (index < num_instructions) {
            throw std::runtime_error("Cannot write to instruction memory.");
            return;
        } else if (index >= MEMORY_LENGTH) {
            throw std::runtime_error("WRITE outside of memory range.");
            return;
        }
        mem[index] = *inport[1]; // + fileLength/4 to protect the instructions from being overwritten
    }
    else{
        std::cout<<"Wrong Control Signal in LoadStoreUnit."<<std::endl;
    }
    return;
}

