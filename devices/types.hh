#ifndef TYPES_HH
#define TYPES_HH
#define NULL 0
#include <cstdint>

typedef long long *inport_t;
typedef long long outport_t;
typedef long long Reg;

// 6*8 = 48 bits for one register line
struct control_signal_t {
    int sig_shifter: 8; // 0x00 for right, 0x01 for left
    int sig_logic: 8; // 0x00 for NOT, 0x01 for AND, 0x10 for OR, 0x11 for XOR
    int sig_register_file: 8; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    int sig_multiport_register_file: 8; // Cuurently same as single port register file
    int sig_multiplexier: 8; //0x00, 0x01, 0x10 and 0x11
    int sig_demultiplexier: 8; //0x00, 0x01, 0x10 and 0x11
};

#endif