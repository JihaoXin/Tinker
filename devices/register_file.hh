#ifndef RESGITER_FILE_HH
#define RESGITER_FILE_HH

#include "device.hh"
#include <iostream>
#include <array>

class RegisterFile : public Device {
public:
    RegisterFile() { 
        cycles = 1;
        area = 20000;
        power = 4.0;
    }
    ~RegisterFile() {}

    void receive_clock(long long control); 
    void receive_clock(){}
    
    void do_function(long long control);
    void do_function(){}
    void connect(int port_id, Latch inLatch);

    std::array<Latch, 2> outLatch;

private:
    std::array<Port, 2> inport;
    std::array<Reg, 32> registers;
    std::array<Port, 2> outport;


};

#endif