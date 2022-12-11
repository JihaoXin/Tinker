#include "control_array.hh"

inline bool check_equal(Signal_array current_line, std::string target_control_signal){
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
    // Initialize the control signal array with fetch&decode instruction in the first begining
    Signal_array fetch_decode_0 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Signal_array fetch_decode_1 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0};
    Signal_array fetch_decode_2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
    Signal_array fetch_decode_3 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0};
    Signal_array fetch_decode_4 = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Signal_array fetch_decode_5 = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    control_registers.push(fetch_decode_0);
    control_registers.push(fetch_decode_1);
    control_registers.push(fetch_decode_2);
    control_registers.push(fetch_decode_3);
    control_registers.push(fetch_decode_4);
    control_registers.push(fetch_decode_5);
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
        std::array<bool, CONTROL_SIGNAL_ARRAY_SIZE> current_line = control_registers.front();
        control_registers.pop();
        if (check_equal(current_line,"111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111") == true){
            outport = NULL;
            return;
        }
        outport->ifd = current_line[0];
        outport->opcode = current_line[1];
        outport->lrd = current_line[2];
        outport->lrs = current_line[3];
        outport->lrt = current_line[4];
        outport->ll = current_line[5];
        outport->lim = current_line[6];
        outport->lrd_dem = current_line[7]*8 + current_line[8]*4 + current_line[9]*2 + current_line[10];
        outport->lrs_dem = current_line[11]*8 + current_line[12]*4 + current_line[13]*2 + current_line[14];
        outport->lrt_dem = current_line[15]*8 + current_line[16]*4 + current_line[17]*2 + current_line[18];
        outport->ll_dem = current_line[19] *8 + current_line[20]*4 + current_line[21]*2 + current_line[22];
        outport->lrd_lrf1 = current_line[23] ;
        outport->lrd_lrf2 = current_line[24];
        outport->lrs_lrf1 = current_line[25];
        outport->lrs_lrf2 = current_line[26];
        outport->lrt_lrf1 = current_line[27];
        outport->lrt_lrf2 = current_line[28];
        outport->ll_l1 = current_line[29];
        outport->ll_l2 = current_line[30];
        outport->lrf1_mux = current_line[31] *8 + current_line[32]*4 + current_line[33]*2 + current_line[34];
        outport->lrf2_mux = current_line[35] *8 + current_line[36]*4 + current_line[37]*2 + current_line[38];
        outport->lrf1 = current_line[39];
        outport->lrf2 = current_line[40];
        outport->register_file = current_line[41] *2 + current_line[42];
        outport->lrf_out_1 = current_line[43];
        outport->lrf_out_2 = current_line[44];
        outport->lrf_out_1_dem = current_line[45] *8 + current_line[46]*4 + current_line[47]*2 + current_line[48];
        outport->lrf_out_2_dem = current_line[49] *8 + current_line[50]*4 + current_line[51]*2 + current_line[52];
        outport->lrf_out_1_out= current_line[53];
        outport->lrf_out_1_ls= current_line[54];
        outport->lrf_out_1_pc= current_line[55];
        outport->lrf_out_1_l1= current_line[56];
        outport->lrf_out_1_lrf1= current_line[57];
        outport->lrf_out_1_l2= current_line[58];
        outport->lrf_out_2_l2= current_line[59];
        outport->l1_mux = current_line[60] *8 + current_line[61]*4 + current_line[62]*2 + current_line[63];
        outport->l2_mux = current_line[64] *8 + current_line[65]*4 + current_line[66]*2 + current_line[67];
        outport->l1 = current_line[68];
        outport->l2 = current_line[69];
        outport->l1_dem = current_line[70] *8 + current_line[71]*4 + current_line[72]*2 + current_line[73];
        outport->l2_dem = current_line[74] *8 + current_line[75]*4 + current_line[76]*2 + current_line[77];
        outport->l_dem1_1 = current_line[78];
        outport->l_dem1_2 = current_line[79];
        outport->l_dem1_3 = current_line[80];
        outport->l_dem1_4 = current_line[81];
        outport->l_dem1_5 = current_line[82];
        outport->l_dem1_6 = current_line[83];
        outport->l_dem1_7 = current_line[84];
        outport->l_dem1_8 = current_line[85];
        outport->l_dem1_9 = current_line[86];
        outport->l_dem2_1 = current_line[87];
        outport->l_dem2_2 = current_line[88];
        outport->l_dem2_3 = current_line[89];
        outport->l_dem2_4 = current_line[90];
        outport->l_dem2_5 = current_line[91];
        outport->l_dem2_6 = current_line[92];
        outport->l_dem2_7 = current_line[93];
        outport->l_dem2_8 = current_line[94];
        outport->shifter = current_line[95]*2 + current_line[96];
        outport->logic = current_line[97]*2 + current_line[98];
        outport->la1 = current_line[99];
        outport->la2 = current_line[100];
        outport->la3 = current_line[101];
        outport->la4 = current_line[102];
        outport->la5 = current_line[103];
        outport->la6 = current_line[104];
        outport->la7 = current_line[105];
        outport->la8 = current_line[106];
        outport->la9 = current_line[107];   
        outport->lalu_mux = current_line[108] *8 + current_line[109]*4 + current_line[110]*2 + current_line[111];
        outport->lalu = current_line[112];
        outport->lalu_dem = current_line[113] *8 + current_line[114]*4 + current_line[115]*2 + current_line[116];
        outport->lalu_l2 = current_line[117];
        outport->lalu_lrf1 = current_line[118];
        outport->lalu_pc = current_line[119];
        outport->lalu_ls_add = current_line[120];
        outport->lalu_lut = current_line[121];
        outport->pc_mux = current_line[122]*8 + current_line[123]*4 + current_line[124]*2 + current_line[125];
        outport->pc = current_line[126];
        outport->pc_dem = current_line[127]*8 + current_line[128]*4 + current_line[129]*2 + current_line[130];
        outport->l_pc_add4 = current_line[131];
        outport->l_pc_ls_add = current_line[132];
        outport->l_pc_l1 = current_line[133];
        outport->l_add4_out = current_line[134];
        outport->address_mux = current_line[135]*8 + current_line[136]*4 + current_line[137]*2 + current_line[138];
        outport->l_ls_address = current_line[139];
        outport->loadstore = current_line[140];
        outport->l_loaddata = current_line[141];
        outport->load_dem = current_line[142] *8 + current_line[143]*4 + current_line[144]*2 + current_line[145];
        outport->l_loaddata_lrf1 = current_line[146];
        outport->lrf_out_1_in = current_line[147];
        outport->l_in_lrf1 = current_line[148];
        outport->lrf_out_2_out = current_line[149];

    }
};