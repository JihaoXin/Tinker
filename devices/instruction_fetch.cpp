
#include "instruction_fetch.hh"

InstructionFetch::InstructionFetch(char const* filename) {
    //Open the binary file of instructions

    instructionFile.open(filename, std::ios::out | std::ios::binary);
    if(!instructionFile) {
      std::cout << "Cannot open instruction file" << std::endl;
    }

    //Metrics (TODO: define them to something)
    cycles = 0;
    area = 0;
    power = 0;

    cycle_counter = 0;
}

InstructionFetch::~InstructionFetch() {
    instructionFile.close();
}

void InstructionFetch::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;

    /* --- Instruction Fetch --- */
    
    //Seek to the program counter's value
    instructionFile.seekg(static_cast<uint32_t>(*inport[0]), std::ios::beg);

    //Read the 32-bits and output it to the port
    instructionFile.read((char *) &outport, sizeof(uint32_t));
}