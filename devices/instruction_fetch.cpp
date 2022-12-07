
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

    // get size of instructionFile in bytes
    instructionFile.seekg(0, instructionFile.end);
    fileLength = instructionFile.tellg();
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
    
    // check if PC from inport is out of bounds
    if (*inport[0] >= fileLength) { // halt fetch = 23458977153024
        // outport = std::numeric_limits<long long>::min(); // all 1's. signifies EOF. 
        outport = 23458977153024; // halt
        return;
    }

    //Seek to the program counter's value
    instructionFile.seekg(static_cast<uint32_t>(*inport[0]), std::ios::beg);

    //Read the 32-bits and output it to the port
    instructionFile.read((char *) &outport, sizeof(uint32_t));
}