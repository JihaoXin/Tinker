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
    std::cout << "Output: ";
    std::cout << *inport[0] << std::endl;
    return;
}
