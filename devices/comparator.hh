#ifndef COMPARATOR_HH
#define COMPARATOR_HH
#include "device.hh"
#include <array>

class Comparator : public Device {
public:
    Comparator();
    ~Comparator();
    void receive_clock();
    std::array<inport_t, 2> inport;
    outport_t outport;
};

#endif