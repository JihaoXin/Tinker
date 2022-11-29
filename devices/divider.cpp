#include "divider.hh"
#include <iostream>
Divider::Divider() {
    cycles = 8;
    area = 5000;
    power = 1.0;
}

Divider::~Divider() {}

void Divider::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;

    outport = *inport[1] == 0 ? LLONG_MAX : *inport[0] / *inport[1];
}
