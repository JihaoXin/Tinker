#ifndef INSTRUCTIONDECODE_HH
#define INSTRUCTIONDECODE_HH
#include "device.hh"
#include <array>
#include <iostream>
#include <fstream>

class InstructionDecode : public Device {
public:
    InstructionDecode();
    ~InstructionDecode();
    void receive_clock();

    //inport[0] must be a pointer for the fetched 32-bit instruction
    std::array<inport_t, 1> inport;
    
    //The decoded 32-bit instruction
    outport_t opcode;
    outport_t register_d;
    outport_t register_s;
    outport_t register_t;
    outport_t literal;
};

#endif