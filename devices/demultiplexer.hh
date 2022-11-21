#ifndef DEMULTIPLEXER_HH
#define DEMULTIPLEXER_HH

#include "device.hh"
#include <array>
#include <iostream>

class Demultiplexer : public Device {
public:
    Demultiplexer() { 
        cycles = 0.5;
        area = 500;
        power = 0.25;
    }
    ~Demultiplexer() {}
    void receive_clock();
    void receive_clock(long long control);
    void do_function();
    void connect(int port_id, Latch inLatch);

    std::array<Latch, 4> outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;
};

#endif