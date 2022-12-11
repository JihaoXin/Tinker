#include "control_array.hh"

inline bool check_equal(std::array<bool,100> current_line, std::string target_control_signal){
    for (int i = 0; i < target_control_signal.size(); i++){
        if ( current_line[i] != static_cast<bool>(target_control_signal[i]-'0') ){
            return false;
        }
    }
    return true;
}


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
        control_signal_array_t *ctr_sigs = inport[0];
        while(ctr_sigs->control_signals.empty() == false){
            control_registers.push(ctr_sigs->control_signals.front());
            ctr_sigs->control_signals.pop();
        }
    }
    cycle_counter = 0;
    if (control_registers.size() > 0 /*& control_registers.size() <= CONTROL_ARRAY_SIZE*/) {
        std::array<bool, 100> current_line = control_registers.front();
        control_registers.pop();
        if (check_equal(current_line,"1111111111111111111111111111111111111111111111111111111111111111") == true){
            outport = NULL;
            return;
        }
        // outport->lrd = (current_line >> 63) & 1;
        outport->lrd = current_line[0];
        // outport->lrs = (current_line >> 62) & 1;
        outport->lrs = current_line[1];
        // outport->lrt = (current_line >> 61) & 1;
        outport->lrt = current_line[2];
        // outport->ll = (current_line >> 60) & 1;
        outport->ll = current_line[3];
        // outport->ll_dem = (current_line >> 58)  & 0b11;
        outport->ll_dem = current_line[4] *2 + current_line[5];
        // outport->lrd_dem = (current_line >> 56) & 0b11;
        outport->lrd_dem = current_line[6] *2 + current_line[7];
        // outport->lrt_dem = (current_line >> 54) & 0b11;
        outport->lrt_dem = current_line[8] *2 + current_line[9];
        // outport->lrf1_mux = (current_line >> 52) & 0b11;
        outport->lrf1_mux = current_line[10] *2 + current_line[11];
        // outport->lrf2_mux = (current_line >> 50) & 0b11;
        outport->lrf2_mux = current_line[12] *2 + current_line[13];
        // outport->lrf1 = (current_line >> 49) & 1;
        outport->lrf1 = current_line[14];
        // outport->lrf2 = (current_line >> 48) & 1;
        outport->lrf2 = current_line[15];
        // outport->register_file = (current_line >> 46) & 0b11;
        outport->register_file = current_line[16] *2 + current_line[17];
        // outport->lrf_out_1 = (current_line >> 45) & 1;
        outport->lrf_out_1 = current_line[18];
        // outport->lrf_out_2 = (current_line >> 44) & 1;
        outport->lrf_out_2 = current_line[19];
        // outport->l1_mux = (current_line >> 42) & 0b11;
        outport->l1_mux = current_line[20] *2 + current_line[21];
        // outport->l2_mux = (current_line >> 40) & 0b11;  
        outport->l2_mux = current_line[22] *2 + current_line[23];
        // outport->l1 = (current_line >> 39) & 1;
        outport->l1 = current_line[24];
        // outport->l2 = (current_line >> 38) & 1;
        outport->l2 = current_line[25];
        // outport->l1_dem = (current_line >> 34) & 0b1111;
        outport->l1_dem = current_line[26] *8 + current_line[27] *4 + current_line[28] *2 + current_line[29];
        // outport->l_dem1_1 = (current_line >> 33) & 1;
        outport->l_dem1_1 = current_line[30];
        // outport->l_dem1_2 = (current_line >> 32) & 1;
        outport->l_dem1_2 = current_line[31];
        // outport->l_dem1_3 = (current_line >> 31) & 1;
        outport->l_dem1_3 = current_line[32];
        // outport->l_dem1_4 = (current_line >> 30) & 1;
        outport->l_dem1_4 = current_line[33];
        // outport->l_dem1_5 = (current_line >> 29) & 1;
        outport->l_dem1_5 = current_line[34];
        // outport->l_dem1_6 = (current_line >> 28) & 1;
        outport->l_dem1_6 = current_line[35];
        // outport->l_dem1_7 = (current_line >> 27) & 1;
        outport->l_dem1_7 = current_line[36];
        // outport->l2_dem = (current_line >> 23) & 0b1111;
        outport->l2_dem = current_line[37] *8 + current_line[38] *4 + current_line[39] *2 + current_line[40];
        // outport->l_dem2_1 = (current_line >> 22) & 1;
        outport->l_dem2_1 = current_line[41];
        // outport->l_dem2_2 = (current_line >> 21) & 1;
        outport->l_dem2_2 = current_line[42];
        // outport->l_dem2_3 = (current_line >> 20) & 1;
        outport->l_dem2_3 = current_line[43];
        // outport->l_dem2_4 = (current_line >> 19) & 1;
        outport->l_dem2_4 = current_line[44];
        // outport->l_dem2_5 = (current_line >> 18) & 1;
        outport->l_dem2_5 = current_line[45];
        // outport->l_dem2_6 = (current_line >> 17) & 1;
        outport->l_dem2_6 = current_line[46];
        // outport->la1 = (current_line >> 16) & 1;
        outport->la1 = current_line[47];
        // outport->la2 = (current_line >> 15) & 1;
        outport->la2 = current_line[48];
        // outport->la3 = (current_line >> 14) & 1;
        outport->la3 = current_line[49];
        // outport->la4 = (current_line >> 13) & 1;
        outport->la4 = current_line[50];
        // outport->la5 = (current_line >> 12) & 1;
        outport->la5 = current_line[51];
        // outport->la6 = (current_line >> 11) & 1;
        outport->la6 = current_line[52];
        // outport->la7 = (current_line >> 10) & 1;
        outport->la7 = current_line[53];
        // outport->lalu_mux = (current_line >> 6) & 0b1111;
        outport->lalu_mux = current_line[54] *8 + current_line[55] *4 + current_line[56] *2 + current_line[57];
        // outport->lalu = (current_line >> 5) & 1;
        outport->lalu = current_line[58];
        // outport->lalu_dem = (current_line >> 3) & 0b11;
        outport->lalu_dem = current_line[59] *2 + current_line[60];
        // outport->shifter = (current_line >> 2) & 0b1;
        outport->shifter = current_line[61];
        // outport->logic = (current_line) & 0b11;
        outport->logic = current_line[62] *2 + current_line[63];

    }
};