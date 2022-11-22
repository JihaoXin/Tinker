#ifndef DEMULTIPLEXER_HH
#define DEMULTIPLEXER_HH

#include "device.hh"
#include <array>

class Demultiplexer : public Device {
public:
    Demultiplexer();
    ~Demultiplexer();
    void receive_clock();
    std::array<inport_t, 1> inport;
    std::array<outport_t, 4> outport;
    inport_t ctrlport;
};

#endif