#ifndef ADD4_HH
#define ADD4_HH
#include "device.hh"
#include <array>
#include <iostream>

class Add4 : public Device {
public:
    Add4() { 
        cycles = 1;
        area = 100;
        power = 0.1;
    }
    ~Add4() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch l);

    Latch outLatch;


private:
    std::array<long long, 1> in;
    long long result;

};


#endif