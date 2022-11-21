#ifndef DEVICE_HH
#define DEVICE_HH

#include "latch.hh"
#include "types.hh"

class Device { // abstract base class
public:
    virtual ~Device() {}
    virtual void receive_clock() = 0;
    // virtual void receive_clock() {receive_clock(NULL);}
    virtual void do_function() = 0;
    // virtual void do_function() {do_function(NULL);}
    virtual void connect(int port_id, Latch inLatch) = 0;

    double cycles;
    double area;
    double power;
    
    

};


#endif