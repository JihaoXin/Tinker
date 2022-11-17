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
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = in[0] + in[1];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    std::array<long long, 2> in;
    long long result;

};


#endif