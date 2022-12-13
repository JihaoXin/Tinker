#ifndef LOADSTORE_HH
#define LOADSTORE_HH

#include "device.hh"
#include <array>
#include <iostream>
#include <fstream>

class Loadstore : public Device {
public:
    Loadstore(char const* filename);
    ~Loadstore();
    void receive_clock();
    void connect_signal(long long sig_value);


    std::array<mem_unit, MEMORY_LENGTH> mem;
    std::array<inport_t, 2> inport; // port 0 -> address, port 1 -> writing value
    std::array<outport_t, 1> outport;
    long long ctrlport; // 0 to read, 1 to store
private:
    int num_instructions;
    std::ifstream instructionFile;
};

#endif