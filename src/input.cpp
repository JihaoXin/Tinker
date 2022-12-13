#include "input.hh"
#include <iostream>
Input::Input() {
    cycles = 1;
    area = 5000;
    power = 1.0;
}

Input::~Input() {}

void Input::receive_clock() {
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    std::cout << "Input: ";
    std::cin >> outport;
    return;
}
