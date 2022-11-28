#include "adder.hh"
#include "add4.hh"
#include "divider.hh"
#include "comparator.hh"
#include "two_complement.hh"
#include "multiplier.hh"
#include "logic.hh"
#include "shifter.hh"
#include "multiplexer.hh"
#include "demultiplexer.hh"
#include "demultiplexer16.hh"
#include "register_file.hh"
#include "mp_register_file.hh"
#include "control_array.hh"
#include "instruction_fetch.hh"
#include "instruction_decode.hh"
#include <iostream>
#include <bitset>

int main () {

    // declare all devices in Execute unit
    Demultiplexer lrd_dem;
    Demultiplexer lrt_dem;
    Demultiplexer ll_dem;
    Multiplexer lrf1_mux;
    Multiplexer lrf2_mux;
    RegisterFile register_file;
    Multiplexer l1_mux;
    Multiplexer l2_mux;
    Demultiplexer16 l1_dem;
    Demultiplexer16 l2_dem;
    Shifter shifter;
    Logic logic;
    Multiplier multiplier;
    Adder adder;
    Add4 add4;
    Comparator comparator;
    Divider divider;
    TwoComplement two_complement;
    Multiplexer lau_mux;
    Demultiplexer lalu_dem;

    /* 
    each device has a latch connected to it, so we need to first define the first latches in the chain
    (and assign a value to them later in the loop)
    */

    Latch lrd;
    Latch lrs;
    Latch lrt;
    Latch lrf_1;
    Latch lrf_2;
    Latch lrf_out_1;
    Latch lrf_out_2;
    Latch l1;
    Latch l2, 
    Latch l_dem1_1;
    Latch l_dem1_2;
    Latch l_dem1_3;
    Latch l_dem1_4;
    Latch l_dem1_5;
    Latch l_dem1_6;
    Latch l_dem1_7;
    Latch l_dem2_1;
    Latch l_dem2_2;
    Latch l_dem2_3;
    Latch l_dem2_4;
    Latch l_dem2_5;
    Latch l_dem2_6;
    latch lalu;





    /*
    .
    .
    .
    */

    /* connect the Latches with the ports of the devices */

    // connect lrd_dem port 0 to lrd latch
    lrd_dem.connect(&lrd.outport, lrd_dem.inport[0]);

    // connect lrt_dem port 0 to lrt latch
    lrt_dem.connect(&lrt.outport, lrt_dem.inport[0]);

    // connect ll_dem port 0 to ll latch
    ll_dem.connect(&ll.outport, ll_dem.inport[0]);

    // conect lrf1_mux
    lrf1_mux.connect(&lrd_dem.outport[0], lrf1_mux.inport[0]);
    lrf1_mux.connect(&lrs.outport, lrf1_mux.inport[1]);
    lrf1_mux.connect(&lrt_dem.outport[0], lrf1_mux.inport[2]);

    //connect lrf2_mux
    lrf1_mux.connect(&lrd_dem.outport[1], lrf2_mux.inport[0]);
    lrf1_mux.connect(&lrt_dem.outport[1], lrf2_mux.inport[1]);

    // connect lrf_1 latch input to lrf1_mux output
    lrf_1.connect(&lrf1_mux.outport, lrf_1.inport);

    // connect lrf_2 latch input to lrf2_mux output
    lrf_2.connect(&lrf2_mux.outport, lrf_2.inport);

    // connect register file to lrf1 and lrf2 
    register_file.connect(&lrf_1.outport, register_file.inport[0]);
    register_file.connect(&lrf_2.outport, register_file.inport[1]);

    // connect lrf_out_1 and lrf_out_2 to register file output
    lrf_out_1.connect(&register_file.outport[0], lrf_out_1.inport);
    lrf_out_2.connect(&register_file.outport[1], lrf_out_2.inport);

    // connect l1 mux to lrf_out_1 and ll_dem
    l1_mux.connect(&lrf_out_1.outport, l1_mux.inport[0]);
    l1_mux.connect(&ll_dem.outport[0], l1_mux.inport[1]);

    // connect l2 mux to lrf_out_2 and ll_dem and lalu_dem
    l2_mux.connect(&lrf_out_2.outport, l2_mux.inport[0]);
    l2_mux.connect(&ll_dem.outport[1], l2_mux.inport[1]);
    l2_mux.connect(&lalu_dem.outport[0], l2_mux.inport[2]);

    // connect l1 latch to l1_mux output
    l1.connect(&l1_mux.outport, l1.inport);

    // connect l2 latch to l2_mux output
    l2.connect(&l2_mux.outport, l2.inport);

    // connect l1 latch to l1_dem input
    l1_dem.connect(&l1.outport, l1_dem.inport[0]);

    // connect l2 latch to l2_dem input
    l2_dem.connect(&l2.outport, l2_dem.inport[0]);

    // connect l_dem1_1 - l_dem1_7 to l1_dem output
    l_dem1_1.connect(&l1_dem.outport[0], l_dem1_1.inport);
    l_dem1_2.connect(&l1_dem.outport[1], l_dem1_2.inport);
    l_dem1_3.connect(&l1_dem.outport[2], l_dem1_3.inport);
    l_dem1_4.connect(&l1_dem.outport[3], l_dem1_4.inport);
    l_dem1_5.connect(&l1_dem.outport[4], l_dem1_5.inport);
    l_dem1_6.connect(&l1_dem.outport[5], l_dem1_6.inport);
    l_dem1_7.connect(&l1_dem.outport[6], l_dem1_7.inport);

    // connect l_dem2_1 - l_dem2_6 to l2_dem output
    l_dem2_1.connect(&l2_dem.outport[0], l_dem2_1.inport);
    l_dem2_2.connect(&l2_dem.outport[1], l_dem2_2.inport);
    l_dem2_3.connect(&l2_dem.outport[2], l_dem2_3.inport);
    l_dem2_4.connect(&l2_dem.outport[3], l_dem2_4.inport);
    l_dem2_5.connect(&l2_dem.outport[4], l_dem2_5.inport);
    l_dem2_6.connect(&l2_dem.outport[5], l_dem2_6.inport);

    // connect l_dem1_7 and l_dem2_6 to adder
    adder.connect(&l_dem1_7.outport, adder.inport[0]);
    adder.connect(&l_dem2_6.outport, adder.inport[1]);

    // connect l_dem1_5 and l_dem2_4 to shifter
    shifter.connect(&l_dem1_5.outport, shifter.inport[0]);
    shifter.connect(&l_dem2_4.outport, shifter.inport[1]);

    // connect l_dem1_3 and l_dem1_2 to logic
    logic.connect(&l_dem1_3.outport, logic.inport[0]);
    logic.connect(&l_dem1_2.outport, logic.inport[1]);

    // connect l_dem1_1 to two's complement
    twos_complement.connect(&l_dem1_1.outport, twos_complement.inport);

    // connect l_dem2_1 and l_dem2_2 to multiplier
    multiplier.connect(&l_dem2_1.outport, multiplier.inport[0]);
    multiplier.connect(&l_dem2_2.outport, multiplier.inport[1]);

    // connect l_dem2_3 l_dem2_4 to divider
    divider.connect(&l_dem2_3.outport, divider.inport[0]);
    divider.connect(&l_dem2_4.outport, divider.inport[1]);

    // connect l_dem2_5 and l_dem2_6 to comparator
    comparator.connect(&l_dem2_5.outport, comparator.inport[0]);
    comparator.connect(&l_dem2_6.outport, comparator.inport[1]);

    // connect lalu mux to adder, shifter, logic, twos_complement, multiplier, divider, comparator
    lalu_mux.connect(&adder.outport, lalu_mux.inport[0]);
    lalu_mux.connect(&shifter.outport, lalu_mux.inport[1]);
    lalu_mux.connect(&logic.outport, lalu_mux.inport[2]);
    lalu_mux.connect(&twos_complement.outport, lalu_mux.inport[3]);
    lalu_mux.connect(&multiplier.outport, lalu_mux.inport[4]);
    lalu_mux.connect(&divider.outport, lalu_mux.inport[5]);
    lalu_mux.connect(&comparator.outport, lalu_mux.inport[6]);
    
    // connect lalu mux to lalu latch
    lalu.connect(&lalu_mux.outport, lalu.inport);

    // connect lalu latch to lalu demux
    lalu_dem.connect(&lalu.outport, lalu_dem.inport[0]);



    //
    /*
    .
    .
    .
    .
    */

    // architecture is now declared and connected. 

    while (/* PC still within program and no halt*/) { // should only pass first inputs, call do_functions, and recieve clocks. 
        // pass input to first devices (first device(s) in dependency chain) probably the PC to the fetch unit. 

        control_signal_t ctr_sig;
        // assign bitfields of ctr_sig to respective devices
        ll_dem.connect(&ctr_sig.ll_dem, ll_dem.ctrlport);
        lrd_dem.connect(&ctr_sig.lrd_dem, lrd_dem.ctrlport);
        lrt_dem.connect(&ctr_sig.lrt_dem, lrt_dem.ctrlport);
        lrf1_mux.connect(&ctr_sig.lrf1_mux, lrf1_mux.ctrlport);
        lrf2_mux.connect(&ctr_sig.lrf2_mux, lrf2_mux.ctrlport);
        register_file.connect(&ctr_sig.register_file, register_file.ctrlport);
        l1_mux.connect(&ctr_sig.l1_mux, l1_mux.ctrlport);
        l2_mux.connect(&ctr_sig.l2_mux, l2_mux.ctrlport);
        l1_dem.connect(&ctr_sig.l1_dem, l1_dem.ctrlport);
        l2_dem.connect(&ctr_sig.l2_dem, l2_dem.ctrlport);
        shifter.connect(&ctr_sig.shifter, shifter.ctrlport);
        logic.connect(&ctr_sig.logic, logic.ctrlport);
        lalu_mux.connect(&ctr_sig.lalu_mux, lalu_mux.ctrlport);
        lalu_dem.connect(&ctr_sig.lalu_dem, lalu_dem.ctrlport);





        // apply do_function() to all devices (IN ORDER) for example:

        // clock edge, apply receive_clock() to all devices

    }

    return 0;
}