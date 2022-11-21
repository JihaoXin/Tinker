#ifndef MP_REGISTER_FILE_HH
#define MP_REGISTER_FILE_HH

#include "device.hh"
#include <array>
#include <iostream>

class MPRegisterFile : public Device {
public:
    MPRegisterFile() { 
        cycles = 1;
        area = 25000;
        power = 6.0;
    }
    ~MPRegisterFile() {}
    void receive_clock(long long control); 
    void receive_clock(){}
    void do_function(long long control);
    void do_function(){}
    void connect(int port_id, Latch inLatch) {inport[port_id] = l.value;}

    std::array<Latch, 4> outLatch;

private:
    std::array<Port, 4> in;
    std::array<Reg, 32> registers;
    std::array<double, 4> result;

};

#endif