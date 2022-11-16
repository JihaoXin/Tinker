#ifndef SHIFTER_HH
#define SHIFTER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Shifter : public Device {
public:
    Shifter(double control) { 
        cycles = 1;
        Area = 200;
        Power = 0.5;
        control = control;
    }
    ~Shifter() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){ result = (control == 0)? (in[0] >> in[1]) : (in[0] << in[1]);}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}
private:
    std::array<Port, 2> in;
    long long result;
    double control;
};

#endif