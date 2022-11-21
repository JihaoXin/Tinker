    #include "logic.hh"

void Logic::receive_clock() {
    // Pass data from outport to outLatch
    outLatch.value = reinterpret_cast<unsigned char*>(outport);
}

void Logic::do_function(){
}

void Logic::do_function(long long control){ 
    if (control == 0) { // 0x00 NOT
        *outport = ~*inport[0];
    } else if (control == 1) { // 0x01 AND
        *outport = *inport[0] & *inport[1];
    } else if (control == 16) { // 0x10 OR
        *outport = *inport[0] | *inport[1];
    } else if (control == 17) { // 0x11 XOR
        *outport = *inport[0] ^ *inport[1];
    }
}

void Logic::connect(int port_id, Latch inLatch){
    // Connect inLatch to inport
    inport[port_id] = reinterpret_cast<Port>(inLatch.value);
}
