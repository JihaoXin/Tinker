#ifndef ADDER_HH
#define ADDER_HH
#include "device.hh"
#include <array>

class Adder : public Device {
public:
    Adder();
    ~Adder();
    void receive_clock();
    std::array<inport_t, 2> inport;
    outport_t outport;
};


#endif