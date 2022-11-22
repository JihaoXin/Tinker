#include "adder.hh"
Adder::Adder() {
    cycles = 1;
    area = 400;
    power = 0.5;
}

Adder::~Adder() {}
void Adder::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = *inport[0] + *inport[1];
}