#include "register_file.hh"
#include <iostream>

RegisterFile::RegisterFile() { 
    cycles = 1;
    area = 20000;
    power = 4.0;

    for(int i = 0; i < size(registers); i++) {
        registers[i] = 0;
    }
}

RegisterFile::~RegisterFile() {

}

void RegisterFile::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }

    printf("ctrlport: %lld, in0: %lld, in1: %lld\n", *ctrlport, *inport[0], *inport[1]);
    cycle_counter = 0;
    if (*ctrlport == 0) { // The register file is idle
        return;
    } else if (*ctrlport == 1) { // Direct the value of the register specified by the value on the first input into the first latch.
        outport[0] = registers[*inport[0]];
    } else if (*ctrlport == 2) { // Direct the values of the registers specified by the value on the first and second input ports, to the first and second output latch, respectively.
        outport[0] = registers[*inport[0]];
        outport[1] = registers[*inport[1]];
    } else if (*ctrlport == 3) { // Store the value on the first input port into the register specified by the value on the second register.
        registers[*inport[1]] = *inport[0];
    }
}

