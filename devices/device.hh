#ifndef DEVICE_HH
#define DEVICE_HH

#include "latch.hh"
#include "types.hh"

class Device { // abstract base class
public:
    virtual ~Device() {}
    virtual void receive_clock() = 0;
    virtual void do_function() = 0;
    virtual void connect(int port_id, Latch l) = 0;

    Latch outLatch; // each device will have its own output latch which is later connected to a devices input ports.
                    // ports will be declared in each device individually. 
    double cycles;
    double area;
    double power;
    
    

};


#endif