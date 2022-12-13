#ifndef MULTIPLIER_HH
#define MULTIPLIER_HH
#include "device.hh"
#include <array>

class Multiplier : public Device { 
public:
    Multiplier();
    ~Multiplier();
    void receive_clock();
    std::array<inport_t,2> inport;
    outport_t outport;
};

#endif