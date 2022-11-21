#include "multiplier.hh"

void Multiplier::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Multiplier::do_function(){
    // Add inport 1 & 2 to outport
    *outport = (*inport[0] * *inport[1]);
}

void Multiplier::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}