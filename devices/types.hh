#ifndef TYPES_HH
#define TYPES_HH
#define NULL 0
#include <cstdint>

typedef long long *inport_t;
typedef long long outport_t;
typedef long long Reg;

// 35 bits
struct control_signal_t {
    unsigned int ll_dem : 2;
    unsigned int lrd_dem : 2; //0x00, 0x01, 0x10 and 0x11
    unsigned int lrt_dem : 2;
    unsigned int lrf1_mux : 2; //0x00, 0x01, 0x10 and 0x11
    unsigned int lrf2_mux : 2;
    unsigned int register_file : 2; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    unsigned int l1_mux : 2; 
    unsigned int l2_mux : 2; 
    unsigned int l1_dem : 4; 
    unsigned int l2_dem : 4; 
    unsigned int shifter : 1; 
    unsigned int logic : 2;
    unsigned int lalu_mux : 4;
    unsigned int lalu_dem : 4;
    
    // from right to left taking from the excel file because of endianness.
    // unsigned int lalu_dem : 4; // MSB
    // unsigned int lalu_mux : 4;
    // unsigned int logic : 2;
    // unsigned int shifter : 1; 
    // unsigned int l2_dem : 4; 
    // unsigned int l1_dem : 4; 
    // unsigned int l2_mux : 2; 
    // unsigned int l1_mux : 2; 
    // unsigned int register_file : 2; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    // unsigned int lrf2_mux : 2;
    // unsigned int lrf1_mux : 2; //0x00, 0x01, 0x10 and 0x11
    // unsigned int lrt_dem :  2;
    // unsigned int lrd_dem :  2; //0x00, 0x01, 0x10 and 0x11
    // unsigned int ll_dem :   2; //LSB
};

// as many control signals as number of cycles 8, this struct will be appened to the control array.
struct control_signal_array_t {
    long long control_signals[8];
};


#endif