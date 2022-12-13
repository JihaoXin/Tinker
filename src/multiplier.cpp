#include "multiplier.hh"
#include <iostream>
Multiplier::Multiplier() {
    cycles = 3;
    area = 2000;
    power = 1.5;
}

Multiplier::~Multiplier() {}

void Multiplier::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    outport = (*inport[0]) * (*inport[1]);
}

