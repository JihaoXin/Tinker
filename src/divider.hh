#ifndef DIVIDER_HH
#define DIVIDER_HH
#include "device.hh"
#include <array>
#include <climits>
class Divider : public Device {
public:
    Divider();
    ~Divider();
    void receive_clock();
    std::array<inport_t, 2> inport;
    outport_t outport;
};

#endif