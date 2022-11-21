#include "register_file.hh"

void RegisterFile::receive_clock() {}

void RegisterFile::receive_clock(long long  control) { // updates the outlatches for the read operations 
    if (control == 1) {
        outLatch[0].value = reinterpret_cast<unsigned char*>(outport[0]);
        outLatch[1].value = 0;
    } else if (control == 16) {
        outLatch[0].value = reinterpret_cast<unsigned char*>(outport[0]);
        outLatch[1].value = reinterpret_cast<unsigned char*>(outport[1]);
    } 
}

void receive_clock(){}
    
void RegisterFile::do_function(long long control){
    if (control == 0) { // The register file is idle
        return;
    } else if (control == 1) { // Direct the value of the register specified by the value on the first input into the first latch.
        *outport[0] = registers[*inport[0]];
    } else if (control == 16) { // Direct the values of the registers specified by the value on the first and second input ports, to the first and second output latch, respectively.
        *outport[0] = registers[*inport[0]];
        *outport[1] = registers[*inport[1]];
    } else if (control == 17) { // Store the value on the first input port into the register specified by the value on the second register.
        registers[*inport[1]] = *inport[0];
    }
}

void RegisterFile::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}
