#ifndef MULTIPLIER_HH
#define MULTIPLIER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Multiplier : public Device { 
public:
    Multiplier() { 
        cycles = 3;
        Area = 2000;
        Power = 1.5;
    }
    ~Multiplier() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = in[0] * in[1];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    std::array<Port, 2> in;
    long long result;

};

#endif