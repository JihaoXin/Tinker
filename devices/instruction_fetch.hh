#ifndef INSTRUCTIONFETCH_HH
#define INSTRUCTIONFETCH_HH
#include "device.hh"
#include <array>
#include <iostream>
#include <fstream>


class InstructionFetch : public Device {
public:
    InstructionFetch(char const* filename);
    InstructionFetch();
    ~InstructionFetch();
    void receive_clock();

    //inport[0] must be a pointer for PC
    std::array<inport_t, 1> inport;
    
    //outport is the 32-bit instruction
    outport_t outport;
private:
    std::ifstream instructionFile;
};

#endif