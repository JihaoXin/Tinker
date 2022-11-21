#ifndef CONTROL_ARRAY_HH
#define CONTROL_ARRAY_HH
#include "device.hh"
#include <array>
#include <queue>
#include <iostream>
// 6*8 = 48 bits for one register line
struct register_line{
    int sig_shifter: 8; // 0x00 for right, 0x01 for left
    int sig_logic: 8; // 0x00 for NOT, 0x01 for AND, 0x10 for OR, 0x11 for XOR
    int sig_register_file: 8; //0x00 NOP, 0x01 R-, 0x10 RR, 0x11 W
    int sig_multiport_register_file: 8; // Cuurently same as single port register file
    int sig_multiplexier: 8; //0x00, 0x01, 0x10 and 0x11
    int sig_demultiplexier: 8; //0x00, 0x01, 0x10 and 0x11
};

class ControlArray : public Device {
public:
    ControlArray() { 
        cycles = 1;
        area = 1;
        power = 0.001;
    }
    ~ControlArray() {}
    void receive_clock();
    void do_function();
    void connect(int port_id, Latch inLatch);

    std::array<Latch, 6> outLatch;


private:
    const int CONTROL_ARRAY_SIZE = 64; // Size of ControlArray
    std::queue<register_line> control_array;
};


#endif