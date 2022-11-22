#include "mp_register_file.hh"

MPRegisterFile::MPRegisterFile() { 
    cycles = 1;
    area = 25000;
    power = 6.0;
}

MPRegisterFile::~MPRegisterFile() {}

void MPRegisterFile::receive_clock(){
    cycle_counter++;
    if (cycle_counter < cycles) {
        return;
    }
    cycle_counter = 0;
    if (*ctrlport == 0) { // The register file is idle
        return;
    } else if (*ctrlport == 1) { // Direct the value of the register specified by the value on the first input into the first latch.
        outport[0] = registers[*inport[0]];
    } else if (*ctrlport == 16) { // Direct the values of the registers specified by the value on the first and second input ports, to the first and second output latch, respectively.
        outport[0] = registers[*inport[0]];
        outport[1] = registers[*inport[1]];
    } else if (*ctrlport == 17) { // Store the value on the first input port into the register specified by the value on the second register.
        registers[*inport[1]] = *inport[0];
    }
}

