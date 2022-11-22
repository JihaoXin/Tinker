#ifndef RESGITER_FILE_HH
#define RESGITER_FILE_HH

#include "device.hh"
#include <array>

class RegisterFile : public Device {
public:
    RegisterFile();
    ~RegisterFile();
    void receive_clock();

    std::array<Reg, 32> registers;
    std::array<inport_t, 2> inport;
    std::array<outport_t, 2> outport;
    inport_t ctrlport;
};

#endif