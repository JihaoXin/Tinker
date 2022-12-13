// Currently Implemented same functionality as register_file
#ifndef MP_REGISTER_FILE_HH
#define MP_REGISTER_FILE_HH

#include "device.hh"
#include <array>

class MPRegisterFile : public Device {
public:
    MPRegisterFile();
    ~MPRegisterFile();
    void receive_clock();
    std::array<Reg, 32> registers;
    std::array<inport_t, 4> inport;
    std::array<outport_t, 4> outport;
    inport_t ctrlport;
};

#endif
