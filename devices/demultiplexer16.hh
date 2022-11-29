#ifndef DEMULTIPLEXER_16_HH
#define DEMULTIPLEXER_16_HH
#include "device.hh"
#include <array>

class Demultiplexer16 : public Device {
public:
    Demultiplexer16();
    ~Demultiplexer16();
    void receive_clock();
    std::array<inport_t, 1> inport;
    std::array<outport_t, 16> outport;
    inport_t ctrlport;
};
#endif