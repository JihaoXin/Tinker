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
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);
    
    Latch outLatch;

private:
    std::array<Port, 1> inport;
    Port outport;

};

#endif