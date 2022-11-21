#ifndef MULTIPLEXER_HH
#define MULTIPLEXER_HH

#include "device.hh"
#include <array>
#include <iostream>

class Multiplexer : public Device {
public:
    Multiplexer() { 
        cycles = 0.5;
        area = 500;
        power = 0.25;
    }
    ~Multiplexer() {}
    void receive_clock();
    void do_function(long long control);
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;

private:
    std::array<Port, 4> inport;
    Port outport;
};

#endif