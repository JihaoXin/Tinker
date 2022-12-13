#include "output.hh"
#include <iostream>
Output::Output() {
    cycles = 1;
    area = 5000;
    power = 1.0;
    ctrlport = 0;
}

Output::~Output() {}

void Output::connect_signal(long long sig_value) {
    ctrlport = sig_value;
}

void Output::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (ctrlport == 1) {
        std::cout << *inport[0];
    }
    return;
}
