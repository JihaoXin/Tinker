#ifndef MULTIPLEXER_HH
#define MULTIPLEXER_HH

#include "device.hh"
#include <array>
#include <iostream>

class Multiplexer : public Device {
public:
    Multiplexer() { 
        cycles = 0.5;
        area = 500;
        power = 0.25;
    }
    ~Multiplexer() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(long long control){
        if (control == 0) {
            result = in[0];
        } else if (control == 1) {
            result = in[1];
        } else if (control == 16) {
            result = in[2];
        } else if (control == 17) {
            result = in[3];
        } 

    }
    void do_function(){}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

    Latch outLatch;

private:
    std::array<long long, 4> in;
    long long result;
};

#endif