#ifndef ADD4_HH
#define ADD4_HH
#include "device.hh"
#include <array>

class Add4 : public Device {
public:
    Add4();
    ~Add4();
    void receive_clock();
    std::array<inport_t, 1> inport;
    outport_t outport;
};


#endif