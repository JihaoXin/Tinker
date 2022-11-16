#ifndef DIVIDER_HH
#define DIVIDER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Divider : public Device {
public:
    Divider() { 
        cycles = 8;
        Area = 5000;
        Power = 1.0;
    }
    ~Divider() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = in[0] / in[1];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    std::array<Port, 2> in;
    long long result;

};

#endif