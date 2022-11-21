#ifndef MULTIPLIER_HH
#define MULTIPLIER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Multiplier : public Device { 
public:
    Multiplier() { 
        cycles = 3;
        area = 2000;
        power = 1.5;
    }
    ~Multiplier() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);
    
    Latch outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;

};

#endif