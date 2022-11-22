#ifndef CONTROL_ARRAY_HH
#define CONTROL_ARRAY_HH
#include "device.hh"
#include <array>
#include <queue>
// inport of control array is a pointer to control signal
// Every cycle, control array 
// Every cycle, control array will send out a control signal
class ControlArray : public Device {
public:
    ControlArray();
    ~ControlArray();
    void receive_clock();
    std::array<inport_t, 1> inport;
    std::array<outport_t, 6> outport;
    int CONTROL_ARRAY_SIZE; // Size of ControlArray
    std::queue<control_signal_t> control_registers;
};

#endif