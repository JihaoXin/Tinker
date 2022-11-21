   #include "multiplexer.hh"

void Multiplexer::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Multiplexer::do_function(){
}

void Multiplexer::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}

void Multiplexer::do_function(long long control){
    if (control == 0) {
        *outport = *inport[0];
    } else if (control == 1) {
        *outport = *inport[1];
    } else if (control == 16) {
        *outport = *inport[2];
    } else if (control == 17) {
        *outport = *inport[3];
    } 
}