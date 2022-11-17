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
    void receive_clock() {outLatch.value = result;}
    void do_function(long long control){ result = (control == 0)? (in[0] >> in[1]) : (in[0] << in[1]);} // right if control = 0, left if control = 1
    void do_function(){}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

    Latch outLatch;
private:
    std::array<long long, 2> in;
    long long result;
};

#endif