#ifndef LOGIC_HH
#define LOGIC_HH
#include "device.hh"
#include <array>
#include <iostream>

class Logic : public Device { 
public:
    Logic() { 
        cycles = 1;
        area = 600;
        power = 0.75;
    }
    ~Logic() {}
    void receive_clock();
    void do_function(long long control);
    void do_function();
    void connect(int port_id, Latch inLatch);

    Latch outLatch;

private:
    std::array<Port, 2> inport;
    Port outport;
};

#endif