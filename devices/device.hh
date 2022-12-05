#ifndef DEVICE_HH
#define DEVICE_HH

#include "latch.hh"
#include "types.hh"
#include <iostream>


class Device { // abstract base class
public:
    Device();
    virtual ~Device();
    virtual void receive_clock() = 0;
    
    void connect(outport_t *p_outport, inport_t &inport_t);

    double cycles;
    double area;
    double power;
    long long cycle_counter;
};


#endif