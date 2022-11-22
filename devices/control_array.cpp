#include "control_array.hh"

ControlArray::ControlArray() { 
    cycles = 1;
    area = 1;
    power = 0.001;
    CONTROL_ARRAY_SIZE = 64;
}

ControlArray::~ControlArray() {}

void ControlArray::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (control_registers.size() > 0){
        control_signal_t current_line = control_registers.front();
        control_registers.pop();
        outport[0] = current_line.sig_shifter;
        outport[1] = current_line.sig_logic;
        outport[2] = current_line.sig_register_file;
        outport[3] = current_line.sig_multiport_register_file;
        outport[4] = current_line.sig_multiplexier;
        outport[5] = current_line.sig_demultiplexier;
    }
};