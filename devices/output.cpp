#include "output.hh"
#include <iostream>
Output::Output() {
    cycles = 1;
    area = 5000;
    power = 1.0;
}

Output::~Output() {}

void Output::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (*ctrlport == 1) {
    std::cout << "Output Device: " << *inport[0] << std::endl;
    }
    return;
}
