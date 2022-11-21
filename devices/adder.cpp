#include "adder.hh"

void Adder::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Adder::do_function(){
    *outport = (*inport[0] + *inport[1]);
}

void Adder::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}