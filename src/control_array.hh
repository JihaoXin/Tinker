#ifndef CONTROL_ARRAY_HH
#define CONTROL_ARRAY_HH
#include "device.hh"
#include <array>
#include <queue>
#include <string>
// inport of control array is a pointer to control signal
// Every cycle, control array 
// Every cycle, control array will send out a control signal
class ControlArray : public Device {
public:
    ControlArray();
    ~ControlArray();
    void receive_clock();
    void connect_array(control_signal_array_t *p_outport, control_signal_array_t* &inport);
    std::array<control_signal_array_t*, 1> inport;
    control_signal_t outport;
    int CONTROL_ARRAY_SIZE; // Size of ControlArray
    std::queue< Signal_array > control_registers;
};

#endif