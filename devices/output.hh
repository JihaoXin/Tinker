#ifndef OUTPUT_HH
#define OUTPUT_HH
#include "device.hh"
class Output : public Device {
public:
    Output();
    ~Output();
    void receive_clock();
    std::array<inport_t, 1> inport;
};

#endif