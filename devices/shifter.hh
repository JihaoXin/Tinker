#ifndef SHIFTER_HH
#define SHIFTER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Shifter : public Device {
public:
    Shifter() { 
        cycles = 1;
        area = 200;
        power = 0.5;
    }
    ~Shifter() {}
    void do_function(long long control); // right if control = 0, left if control = 1
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;
};

#endif