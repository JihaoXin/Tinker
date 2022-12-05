#ifndef LOOKUP_HH
#define LOOKUP_HH

#include "types.hh"
#include "device.hh"
#include <array>
#include <map>


class Lookup : public Device {
public:
    Lookup();
    ~Lookup();
    void receive_clock();
    void populate_signals();
    void populate_table();
    std::array<inport_t, 1> inport;
    control_signal_array_t outport;
    std::map<long long, control_signal_array_t> lookup_table;
    control_signal_array_t add;
    control_signal_array_t addi;
    control_signal_array_t sub;
};

#endif