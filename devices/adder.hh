#ifndef ADDER_HH
#define ADDER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Adder : public Device {
public:
    Adder() { 
        cycles = 1;
        area = 400;
        power = 0.5;
    }
    ~Adder() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;

};


#endif