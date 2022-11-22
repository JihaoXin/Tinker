
#include "instruction_fetch.hh"

InstructionFetch::InstructionFetch(char const* filename) {
    //Open the binary file of instructions

    instructionFile.open(filename, std::ios::out | std::ios::binary);
    if(!instructionFile) {
      std::cout << "Cannot open instruction file" << std::endl;
    }

    outport = new long long[1];
}

void InstructionFetch::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void InstructionFetch::do_function(uint32_t PC) {
    /* --- Instruction Fetch --- */
    
    //Seek to the program counter's value
    instructionFile.seekg(PC, std::ios::beg);

    //Read the 32-bits and output it to the latch
    instructionFile.read((char *) outport, sizeof(instruction_t));
}

void InstructionFetch::do_function() {}

void InstructionFetch::connect(int port_id, Latch inLatch) {
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}