#ifndef INPUT_HH
#define INPUT_HH
#include "device.hh"
class Input : public Device {
public:
    Input();
    ~Input();
    void receive_clock();
    outport_t outport;
};

#endif