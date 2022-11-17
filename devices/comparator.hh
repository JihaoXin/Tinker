#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "device.hh"
#include <array>
#include <iostream>

class Comparator : public Device {
public:
    Comparator() { 
        cycles = 1;
        area = 200;
        power = 0.25;
    }
    ~Comparator() {}
    void receive_clock() {outLatch.value = result;}
    void do_function(){result = !(in[0] == in[1]);}
    void connect(int port_id, Latch l) {in[port_id] = l.value;}

private:
    std::array<Port, 2> in;
    double result;

};

#endif