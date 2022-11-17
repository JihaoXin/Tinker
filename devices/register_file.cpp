#include "register_file.hh"

void RegisterFile::receive_clock(long long  control) { // updates the outlatches for the read operations 
    if (control == 1) {
        outLatch[0].value = result[0];
        outLatch[1].value = 0;
    } else if (control == 16) {
        outLatch[0].value = result[0];
        outLatch[1].value = result[1];
    } 
}

    void receive_clock(){}
    
void RegisterFile::do_function(long long control){
    if (control == 0) { // The register file is idle
        return;
    } else if (control == 1) { // Direct the value of the register specified by the value on the first input into the first latch.
        result[0] = registers[in[0]];
    } else if (control == 16) { // Direct the values of the registers specified by the value on the first and second input ports, to the first and second output latch, respectively.
        result[0] = registers[in[0]];
        result[1] = registers[in[1]];
    } else if (control == 17) { // Store the value on the first input port into the register specified by the value on the second register.
        registers[in[1]] = in[0];
    }
}
