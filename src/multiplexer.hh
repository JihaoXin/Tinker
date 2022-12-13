#ifndef MULTIPLEXER_HH
#define MULTIPLEXER_HH

#include "device.hh"
#include <array>

class Multiplexer : public Device {
public:
    Multiplexer();
    ~Multiplexer();
    void receive_clock();
    std::array<inport_t, 4> inport;
    outport_t outport;
    inport_t ctrlport;
};

#endif