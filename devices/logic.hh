#ifndef LOGIC_HH
#define LOGIC_HH
#include "device.hh"
#include <array>

class Logic : public Device { 
public:
    Logic();
    ~Logic();
    void receive_clock();
    std::array<inport_t, 2> inport;
    outport_t outport;
    inport_t ctrlport;
};
#endif