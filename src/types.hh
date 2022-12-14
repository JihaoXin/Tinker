#ifndef TYPES_HH
#define TYPES_HH
#define NULL 0
#include <cstdint>
#include <array>
#define MAX_CONTROL_SIGNALS 50
#define CONTROL_SIGNAL_BITS 64
#define CONTROL_SIGNAL_ARRAY_SIZE 150
#define MEMORY_LENGTH 100
typedef long long *inport_t;
typedef long long outport_t;
typedef long long Reg;
typedef long long mem_unit;
typedef std::array<bool,CONTROL_SIGNAL_ARRAY_SIZE> Signal_array; 
// 150 bits
struct control_signal_t {
    long long ifd;
    long long opcode;
    long long lrd;
    long long lrs;
    long long lrt;
    long long ll;
    long long lim;
    long long lrd_dem; //0x00, 0x01, 0x10 and 0x11
    long long lrs_dem;
    long long lrt_dem;
    long long ll_dem;
    long long lrd_lrf1;
    long long lrd_lrf2;
    long long lrs_lrf1;
    long long lrs_lrf2;
    long long lrt_lrf1;
    long long lrt_lrf2;
    long long ll_l1;
    long long ll_l2;
    long long lrf1_mux; //0x00, 0x01, 0x10 and 0x11
    long long lrf2_mux;
    long long lrf1;
    long long lrf2;
    long long register_file; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    long long lrf_out_1;
    long long lrf_out_2;
    long long lrf_out_1_dem;
    long long lrf_out_2_dem;
    long long lrf_out_1_out;
    long long lrf_out_1_ls;
    long long lrf_out_1_pc;
    long long lrf_out_1_l1;
    long long lrf_out_1_lrf1;
    long long lrf_out_1_l2;
    long long lrf_out_2_l2;
    long long l1_mux; 
    long long l2_mux; 
    long long l1;
    long long l2;
    long long l1_dem; 
    long long l2_dem;
    long long l_dem1_1;
    long long l_dem1_2;
    long long l_dem1_3;
    long long l_dem1_4;
    long long l_dem1_5;
    long long l_dem1_6;
    long long l_dem1_7;
    long long l_dem1_8;
    long long l_dem1_9;
    long long l_dem2_1;
    long long l_dem2_2;
    long long l_dem2_3;
    long long l_dem2_4;
    long long l_dem2_5;
    long long l_dem2_6;
    long long l_dem2_7;
    long long l_dem2_8;
    long long shifter; 
    long long logic;
    long long la1;  // we don't have this in the diagram
    long long la2;
    long long la3;
    long long la4;
    long long la5;
    long long la6;
    long long la7;
    long long la8;
    long long la9;
    long long lalu_mux;
    long long lalu;
    long long lalu_dem;
    long long lalu_l2;
    long long lalu_lrf1;
    long long lalu_pc;
    long long lalu_ls_add;
    long long lalu_lut;
    long long pc_mux;
    long long pc;
    long long pc_dem;
    long long l_pc_add4;
    long long l_pc_ls_add;
    long long l_pc_l1;
    long long l_add4_out;
    long long address_mux;
    long long l_ls_address;
    long long loadstore;
    long long l_load_data;
    long long load_dem;
    long long l_load_data_lrf1;
    long long lrf_out_1_in;
    long long l_in_lrf1;
    long long lrf_out_2_out;


    // long long ll_dem : 2;
    // long long lrd_dem : 2; //0x00, 0x01, 0x10 and 0x11
    // long long lrt_dem : 2;
    // long long lrf1_mux : 2; //0x00, 0x01, 0x10 and 0x11
    // long long lrf2_mux : 2;
    // long long register_file : 2; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    // long long l1_mux : 2; 
    // long long l2_mux : 2; 
    // long long l1_dem : 4; 
    // long long l2_dem : 4; 
    // long long shifter : 1; 
    // long long logic : 2;
    // long long lalu_mux : 4;
    // long long lalu_dem : 4;
    
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

struct control_signal_array_t {
    int size; // number of control signals
    std::array< Signal_array,MAX_CONTROL_SIGNALS >  control_signals; // MAX_CONTROL_SIGNALS rows, each row is 100 bits to represent one control signal
};



#endif