#ifndef TWO_COMPLEMENT_HH
#define TWO_COMPLEMENT_HH
#include "device.hh"
#include <array>
#include <iostream>

class TwoComplement : public Device {
public:
    TwoComplement() { 
        cycles = 1;
        area = 200;
        power = 0.25;
    }
    ~TwoComplement() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = -in[0];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

    Latch outLatch;
private:    
    std::array<long long, 1> in;
    long long result;

};

#endif