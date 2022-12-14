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
    void connect_signal(long long sig_value);
    std::array<inport_t, 1> inport;
    long long ctrlport;
    control_signal_array_t outport;
    std::map<long long, control_signal_array_t> lookup_table;
    control_signal_array_t none_operation;
    control_signal_array_t add;
    control_signal_array_t addi;
    control_signal_array_t sub;
    control_signal_array_t subi;
    control_signal_array_t mul;
    control_signal_array_t div;
    control_signal_array_t out;
    control_signal_array_t halt;
};

#endif