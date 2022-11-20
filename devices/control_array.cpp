#include "control_array.hh"
void ControlArray::receive_clock(){
    if (control_array.size() > 0){
        register_line current_line = control_array.front();
        control_array.pop();
        outLatch[0].value = current_line.sig_shifter;
        outLatch[1].value = current_line.sig_logic;
        outLatch[2].value = current_line.sig_register_file;
        outLatch[3].value = current_line.sig_multiport_register_file;
        outLatch[4].value = current_line.sig_multiplexier;
        outLatch[5].value = current_line.sig_demultiplexier;
    }
};
void ControlArray::do_function(){
    // Do nothing
    return;
};
void ControlArray::connect(int port_id, Latch l){
    // Currently Do nothing
    // Should take an instruction input
    // Then analysis the instruction and push the corresponding control signal to the control array
    return;
};