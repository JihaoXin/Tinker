#include "two_complement.hh"

void TwoComplement::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void TwoComplement::do_function(){
    *outport = -(*inport[0]);
}

void TwoComplement::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}