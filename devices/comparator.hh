#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "device.hh"
#include <array>
#include <iostream>

class Comparator : public Device {
public:
    Comparator() { 
        cycles = 1;
        area = 200;
        power = 0.25;
    }
    ~Comparator() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;
private:
    std::array<Port, 2> inport;
    Port outport;

};

#endif