#ifndef DEMULTIPLEXER_HH
#define DEMULTIPLEXER_HH

#include "device.hh"
#include <array>

class Demultiplexer : public Device {
public:
    Demultiplexer();
    ~Demultiplexer();
    void receive_clock();
    void connect_signal(long long sig_value);
    std::array<inport_t, 1> inport;
    std::array<outport_t, 4> outport;
    long long ctrlport;
};

#endif