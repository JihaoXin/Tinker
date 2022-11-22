#ifndef SHIFTER_HH
#define SHIFTER_HH
#include "device.hh"
#include <array>

class Shifter : public Device {
public:
    Shifter();
    ~Shifter();
    void receive_clock();
    std::array<inport_t, 2> inport;
    outport_t outport;
    inport_t ctrlport;
};

#endif