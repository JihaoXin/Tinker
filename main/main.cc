int main () {

    /* declare all devices */
    Adder *adder = new Adder();
    Comparator *comparator = new Comparator();
    Divider *divider = new Divider(); // will need devices to be pointers. 
    Demultiplexer *demux1 = new Demultiplexer();
    Multiplexer *mux1 = new Multiplexer();
    /*
    . 
    .
    .
    */

    /* 
    each device has a latch connected to it, so we need to first define the first latches in the chain
    (and assign a value to them later in the loop)
    */

    Latch LRD;
    Latch LRS;
    Latch LRT;

    /*
    .
    .
    .
    */

    /* connect the Latches with the ports of the devices */

    // LRT connects to input of demux1 
    demux1->connect(0, LRT);

    // connect mux1 ports to output of demux1 and LRD 
    mux1->connect(0, demux1->outLatch);
    mux1->connect(1, LRD);

    /*
    .
    .
    .
    .
    */

    // architecture is now declared and connected. 

    while (/* PC still within program and no halt*/) { // should only pass first inputs, call do_functions, and recieve clocks. 
        // pass input to first devices (first device(s) in dependency chain) probably the PC to the fetch unit. 

        // attach control signals to the devices 

        // apply do_function() to all devices (IN ORDER) for example:

        // clock edge, apply receive_clock() to all devices

    }

    return 0;
}