#ifndef LOADSTORE_HH
#define LOADSTORE_HH

#include "device.hh"
#include <array>

class Loadstore : public Device {
public:
    Loadstore();
    ~Loadstore();
    void receive_clock();

    std::array<mem_unit, 100> mem;
    std::array<inport_t, 2> inport; // port 0 -> address, port 1 -> writing value
    std::array<outport_t, 1> outport;
    inport_t ctrlport; // 0 to read, 1 to store
};

#endif