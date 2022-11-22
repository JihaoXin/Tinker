#ifndef TWO_COMPLEMENT_HH
#define TWO_COMPLEMENT_HH
#include "device.hh"
#include <array>
#include <iostream>

class TwoComplement : public Device {
public:
    TwoComplement();
    ~TwoComplement();
    void receive_clock();
    std::array<inport_t, 1> inport;
    outport_t outport;
}; 

#endif