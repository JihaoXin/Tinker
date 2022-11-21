#ifndef INSTRUCTIONDECODE_HH
#define INSTRUCTIONDECODE_HH
#include "device.hh"
#include <iostream>
#include <fstream>

class InstructionDecode : public Device {
public:
    instruction_t instr;

    InstructionDecode() {}
    ~InstructionDecode() {}
    void receive_clock() {}
    void do_function() {}
    void connect(int port_id, Latch inLatch) {}

    Latch opcode_l;
    Latch register_d_l;
    Latch register_s_l;
    Latch register_t_l;
    Latch literal_l;
private:
    std::array<Port, 2> inport;
    Port out_opcode;
    Port out_register_d;
    Port out_register_s;
    Port out_register_t;
    Port out_literal;

    std::ifstream instructionFile;
    

};

#endif