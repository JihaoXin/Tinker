#ifndef MULTIPLEXER16_HH
#define MULTIPLEXER16_HH

#include "device.hh"
#include <array>

class Multiplexer16 : public Device {
public:
    Multiplexer16();
    ~Multiplexer16();
    void receive_clock();
    void connect_signal(long long sig_value);
    std::array<inport_t, 16> inport;
    outport_t outport;
    long long ctrlport;
};

#endif