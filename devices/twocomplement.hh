#ifndef TWOCOMPLEMENT_HH
#define TWOCOMPLEMENT_HH
#include "device.hh"
#include <array>
#include <iostream>

class TwoComplement : public Device {
public:
    TwoComplement() { 
        cycles = 1;
        Area = 200;
        Power = 0.25;
    }
    ~TwoComplement() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = ~in[0] + 1;}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:    
    std::array<Port, 1> in;
    long long result;

};

#endif