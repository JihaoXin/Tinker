#ifndef LOGIC_HH
#define LOGIC_HH
#include "device.hh"
#include <array>
#include <iostream>

class Logic : public Device { 
public:
    Logic(long long cntrl) { 
        control = cntrl;
        cycles = 1;
        area = 600;
        power = 0.75;
    }
    ~Logic() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){ 
        if (control == 0) { // 0x00 NOT
            result = ~in[0];
        } else if (control == 1) { // 0x01 AND
            result = in[0] & in[1];
        } else if (control == 16) { // 0x10 OR
            result = in[0] | in[1];
        } else if (control == 17) { // 0x11 XOR
            result = in[0] ^ in[1];
        }
        
    }
    void connect(int port_id, Latch l) {in[port_id] = l.value;}
private:
    std::array<long long, 2> in;
    long long result;
    long long control;
};

#endif