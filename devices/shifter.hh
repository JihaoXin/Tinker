#ifndef SHIFTER_HH
#define SHIFTER_HH
#include "device.hh"
#include <array>
#include <iostream>

class Shifter : public Device {
public:
    Shifter(double cntrl) { 
        cycles = 1;
        area = 200;
        power = 0.5;
        control = cntrl;
    }
    ~Shifter() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){ result = (control == 0)? (in[0] >> in[1]) : (in[0] << in[1]);}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}
private:
    std::array<long long, 2> in;
    long long result;
    long long control;
};

#endif