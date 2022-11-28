#include "control_array.hh"

ControlArray::ControlArray() { 
    cycles = 1;
    area = 1;
    power = 0.001;
    outport = new control_signal_t();
    CONTROL_ARRAY_SIZE = 64; // for now. 
}

ControlArray::~ControlArray() { delete outport; }

void ControlArray::connect_array(control_signal_array_t *p_outport, control_signal_array_t* &inport) {

    inport = p_outport;
}

void ControlArray::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    // insert to the queue 
    if (inport[0] != NULL) { 
        control_signal_array_t ctr_sigs = *inport[0];
        control_registers.push(ctr_sigs.control_signals[0]);
        control_registers.push(ctr_sigs.control_signals[1]);
        control_registers.push(ctr_sigs.control_signals[2]);
        control_registers.push(ctr_sigs.control_signals[3]);
        control_registers.push(ctr_sigs.control_signals[4]);
        control_registers.push(ctr_sigs.control_signals[5]);
        control_registers.push(ctr_sigs.control_signals[6]);
        control_registers.push(ctr_sigs.control_signals[7]);
    }
    cycle_counter = 0;
    if (control_registers.size() > 0 & control_registers.size() <= CONTROL_ARRAY_SIZE) {
        outport_t current_line = control_registers.front();
        control_registers.pop();

        outport->ll_dem = (current_line >> 33)  & 0b11;
        outport->lrd_dem = (current_line >> 31) & 0b11;
        outport->lrt_dem = (current_line >> 29) & 0b11;
        outport->lrf1_mux = (current_line >> 27) & 0b11;
        outport->lrf2_mux = (current_line >> 25) & 0b11;
        outport->register_file = (current_line >> 23) & 0b11;
        outport->l1_mux = (current_line >> 21) & 0b11;
        outport->l2_mux = (current_line >> 19) & 0b11;  
        outport->l1_dem = (current_line >> 15) & 0b1111;
        outport->l2_dem = (current_line >> 11) & 0b1111;
        outport->shifter = (current_line >> 10) & 0b1;
        outport->logic = (current_line >> 8) & 0b11;
        outport->lalu_mux = (current_line >> 4) & 0b1111;
        outport->lalu_dem = (current_line) & 0b1111;

    }
};