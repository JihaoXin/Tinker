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
        for (int i = 0; i < ctr_sigs.size; i++) {
            control_registers.push(ctr_sigs.control_signals[i]);
        }
    }
    cycle_counter = 0;
    if (control_registers.size() > 0 /*& control_registers.size() <= CONTROL_ARRAY_SIZE*/) {
        outport_t current_line = control_registers.front();
        control_registers.pop();

        if (current_line == 0b1111111111111111111111111111111111111111111111111111111111111111){
            outport = NULL;
            return;
        }

        outport->lrd = (current_line >> 63) & 1;
        outport->lrs = (current_line >> 62) & 1;
        outport->lrt = (current_line >> 61) & 1;
        outport->ll = (current_line >> 60) & 1;
        outport->ll_dem = (current_line >> 58)  & 0b11;
        outport->lrd_dem = (current_line >> 56) & 0b11;
        outport->lrt_dem = (current_line >> 54) & 0b11;
        outport->lrf1_mux = (current_line >> 52) & 0b11;
        outport->lrf2_mux = (current_line >> 50) & 0b11;
        outport->lrf1 = (current_line >> 49) & 1;
        outport->lrf2 = (current_line >> 48) & 1;
        outport->register_file = (current_line >> 46) & 0b11;
        outport->lrf_out_1 = (current_line >> 45) & 1;
        outport->lrf_out_2 = (current_line >> 44) & 1;
        outport->l1_mux = (current_line >> 42) & 0b11;
        outport->l2_mux = (current_line >> 40) & 0b11;  
        outport->l1 = (current_line >> 39) & 1;
        outport->l2 = (current_line >> 38) & 1;
        outport->l1_dem = (current_line >> 34) & 0b1111;
        outport->l_dem1_1 = (current_line >> 33) & 1;
        outport->l_dem1_2 = (current_line >> 32) & 1;
        outport->l_dem1_3 = (current_line >> 31) & 1;
        outport->l_dem1_4 = (current_line >> 30) & 1;
        outport->l_dem1_5 = (current_line >> 29) & 1;
        outport->l_dem1_6 = (current_line >> 28) & 1;
        outport->l_dem1_7 = (current_line >> 27) & 1;
        outport->l2_dem = (current_line >> 23) & 0b1111;
        outport->l_dem2_1 = (current_line >> 22) & 1;
        outport->l_dem2_2 = (current_line >> 21) & 1;
        outport->l_dem2_3 = (current_line >> 20) & 1;
        outport->l_dem2_4 = (current_line >> 19) & 1;
        outport->l_dem2_5 = (current_line >> 18) & 1;
        outport->l_dem2_6 = (current_line >> 17) & 1;
        outport->la1 = (current_line >> 16) & 1;
        outport->la2 = (current_line >> 15) & 1;
        outport->la3 = (current_line >> 14) & 1;
        outport->la4 = (current_line >> 13) & 1;
        outport->la5 = (current_line >> 12) & 1;
        outport->la6 = (current_line >> 11) & 1;
        outport->la7 = (current_line >> 10) & 1;
        outport->lalu_mux = (current_line >> 6) & 0b1111;
        outport->lalu = (current_line >> 5) & 1;
        outport->lalu_dem = (current_line >> 3) & 0b11;

        outport->shifter = (current_line >> 2) & 0b1;
        outport->logic = (current_line) & 0b11;

    }
};