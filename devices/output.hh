#ifndef OUTPUT_HH
#define OUTPUT_HH
#include "device.hh"
class Output : public Device {
public:
    Output();
    ~Output();
    void receive_clock();
    std::array<inport_t, 2> inport;
    inport_t ctrlport;
};

#endif