#ifndef OUTPUT_HH
#define OUTPUT_HH
#include "device.hh"
class Output : public Device {
public:
    Output();
    ~Output();
    void receive_clock();
    void connect_signal(long long sig_value);
    std::array<inport_t, 1> inport;
    long long ctrlport;
};

#endif