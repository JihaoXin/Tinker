#ifndef DEMULTIPLEXER_HH
#define DEMULTIPLEXER_HH

#include "device.hh"
#include <array>
#include <iostream>

class Demultiplexer : public Device {
public:
    Demultiplexer() { 
        cycles = 0.5;
        area = 500;
        power = 0.25;
    }
    ~Demultiplexer() {}
    void receive_clock() {}
    void receive_clock(long long control) {
        if (control == 0) {
            outLatch[0].value = result;
            outLatch[1].value = 0;
            outLatch[2].value = 0;
            outLatch[3].value = 0;
        } else if (control == 1) {
            outLatch[0].value = 0;
            outLatch[1].value = result;
            outLatch[2].value = 0;
            outLatch[3].value = 0;
        } else if (control == 16) {
            outLatch[0].value = 0;
            outLatch[1].value = 0;
            outLatch[2].value = result;
            outLatch[3].value = 0;
        } else if (control == 17) {
            outLatch[0].value = 0;
            outLatch[1].value = 0;
            outLatch[2].value = 0;
            outLatch[3].value = result;
        } 
    }
    void do_function(){ result = in[0];}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

    std::array<Latch, 4> outLatch;

private:
    std::array<Port, 1> in;
    double result;
};

#endif