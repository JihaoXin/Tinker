#include "multiplexer16.hh"

Multiplexer16::Multiplexer16() {
    cycles = 0.5;
    area = 500;
    power = 0.25;
}

Multiplexer16::~Multiplexer16() {}

void Multiplexer16::connect_signal(long long sig_value) {
    ctrlport = sig_value;
}

void Multiplexer16::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = *inport[ctrlport];
}