#ifndef DIVIDER_HH
#define DIVIDER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Divider : public Device {
public:
    Divider() { 
        cycles = 8;
        area = 5000;
        power = 1.0;
    }
    ~Divider() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;
};

#endif