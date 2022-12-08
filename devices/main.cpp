#include "adder.hh"
#include "add4.hh"
#include "divider.hh"
#include "comparator.hh"
#include "two_complement.hh"
#include "multiplier.hh"
#include "logic.hh"
#include "shifter.hh"
#include "multiplexer.hh"
#include "multiplexer16.hh"
#include "demultiplexer.hh"
#include "demultiplexer16.hh"
#include "register_file.hh"
#include "mp_register_file.hh"
#include "control_array.hh"
#include "instruction_fetch.hh"
#include "instruction_decode.hh"
#include "lookup.hh"
#include "loadstore.hh"
#include <iostream>
#include <bitset>

int main () {

    // declare all devices in Execute unit
    InstructionDecode decoder;
    InstructionFetch fetcher("code");
    Lookup lookup;
    ControlArray control_array;
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
    TwoComplement twos_complement;
    Multiplexer16 lalu_mux;
    Demultiplexer lalu_dem;

    /* 
    each device has a latch connected to it, so we need to first define the first latches in the chain
    (and assign a value to them later in the loop)
    */

    Latch pc;
    pc.outport = 0;
    Latch ifd;
    Latch lrd;
    Latch lrs;
    Latch lrt;
    Latch ll;
    Latch opcode;
    Latch lrf_1;
    Latch lrf_2;
    Latch lrf_out_1;
    Latch lrf_out_2;
    Latch l1;
    Latch l2;
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
    Latch la1;
    Latch la2;
    Latch la3;
    Latch la4;
    Latch la5;
    Latch la6;
    Latch la7;
    Latch lalu;





    /*
    .
    .
    .
    */

    /* connect the Latches with the ports of the devices */

    //PC Latch -> Instruction Fetch
    fetcher.connect(&pc.outport, fetcher.inport[0]);

    //Instruction Fetch -> IFD Latch
    ifd.connect(&fetcher.outport);

    //IFD Latch -> Instruction Decode
    decoder.connect(&ifd.outport, decoder.inport[0]);

    // outport_t lrd_val = 5;
    // outport_t lrs_val = 4;
    // outport_t lrt_val = 3;
    // outport_t ll_val = 0;
    // outport_t opcode_val = 2;

    // connect lrd latch to decoder register_d
    lrd.connect(&decoder.register_d);
    // lrd.connect(&lrd_val);

    // connect lrs latch to decoder register_s
    lrs.connect(&decoder.register_s);
    // lrs.connect(&lrs_val);

    // connect lrt latch to decoder register_t
    lrt.connect(&decoder.register_t);
    // lrt.connect(&lrt_val);

    // connect ll latch to decoder literal
    ll.connect(&decoder.literal);
    // ll.connect(&ll_val);

    // connect opcode latch to decoder opcode
    opcode.connect(&decoder.opcode);
    // opcode.connect(&opcode_val);

    // connect lrd_dem port 0 to lrd latch
    lrd_dem.connect(&lrd.outport, lrd_dem.inport[0]);

    // connect lrt_dem port 0 to lrt latch
    lrt_dem.connect(&lrt.outport, lrt_dem.inport[0]);

    // connect ll_dem port 0 to ll latch
    ll_dem.connect(&ll.outport, ll_dem.inport[0]);

    // connect lookup port 0 to opcode latch
    lookup.connect(&opcode.outport, lookup.inport[0]);

    // connect lookup to control array
    control_array.connect_array(&lookup.outport, control_array.inport[0]);


    // conect lrf1_mux
    lrf1_mux.connect(&lrd_dem.outport[0], lrf1_mux.inport[0]);
    lrf1_mux.connect(&lrs.outport, lrf1_mux.inport[1]);
    lrf1_mux.connect(&lrt_dem.outport[0], lrf1_mux.inport[2]);
    lrf1_mux.connect(&lalu_dem.outport[0], lrf1_mux.inport[3]);

    //connect lrf2_mux
    lrf2_mux.connect(&lrd_dem.outport[1], lrf2_mux.inport[0]);
    lrf2_mux.connect(&lrt_dem.outport[1], lrf2_mux.inport[1]);

    // connect lrf_1 latch input to lrf1_mux output
    lrf_1.connect(&lrf1_mux.outport);

    // connect lrf_2 latch input to lrf2_mux output
    lrf_2.connect(&lrf2_mux.outport);

    // connect register file to lrf1 and lrf2 
    register_file.connect(&lrf_1.outport, register_file.inport[0]);
    register_file.connect(&lrf_2.outport, register_file.inport[1]);

    // connect lrf_out_1 and lrf_out_2 to register file output
    lrf_out_1.connect(&register_file.outport[0]);
    lrf_out_2.connect(&register_file.outport[1]);

    // connect l1 mux to lrf_out_1 and ll_dem
    l1_mux.connect(&lrf_out_1.outport, l1_mux.inport[0]);
    l1_mux.connect(&ll_dem.outport[0], l1_mux.inport[1]);
    l1_mux.connect(&lalu_dem.outport[1], l1_mux.inport[1]);

    // connect l2 mux to lrf_out_2 and ll_dem and lalu_dem
    l2_mux.connect(&lrf_out_2.outport, l2_mux.inport[0]);
    l2_mux.connect(&ll_dem.outport[1], l2_mux.inport[1]);
    l2_mux.connect(&lalu_dem.outport[1], l2_mux.inport[2]);

    // connect l1 latch to l1_mux output
    l1.connect(&l1_mux.outport);

    // connect l2 latch to l2_mux output
    l2.connect(&l2_mux.outport);

    // connect l1 latch to l1_dem input
    l1_dem.connect(&l1.outport, l1_dem.inport[0]);

    // connect l2 latch to l2_dem input
    l2_dem.connect(&l2.outport, l2_dem.inport[0]);

    // connect l_dem1_1 - l_dem1_7 to l1_dem output
    l_dem1_1.connect(&l1_dem.outport[0]);
    l_dem1_2.connect(&l1_dem.outport[1]);
    l_dem1_3.connect(&l1_dem.outport[2]);
    l_dem1_4.connect(&l1_dem.outport[3]);
    l_dem1_5.connect(&l1_dem.outport[4]);
    l_dem1_6.connect(&l1_dem.outport[5]);
    l_dem1_7.connect(&l1_dem.outport[6]);

    // connect l_dem2_1 - l_dem2_6 to l2_dem output
    l_dem2_1.connect(&l2_dem.outport[0]);
    l_dem2_2.connect(&l2_dem.outport[1]);
    l_dem2_3.connect(&l2_dem.outport[2]);
    l_dem2_4.connect(&l2_dem.outport[3]);
    l_dem2_5.connect(&l2_dem.outport[4]);
    l_dem2_6.connect(&l2_dem.outport[5]);

    // connect l_dem1_1 and l_dem1_2 to adder
    adder.connect(&l_dem1_1.outport, adder.inport[0]);
    adder.connect(&l_dem2_1.outport, adder.inport[1]);

    // connect l_dem1_3 and l_dem1_4 to shifter
    shifter.connect(&l_dem1_2.outport, shifter.inport[0]);
    shifter.connect(&l_dem2_2.outport, shifter.inport[1]);

    // connect l_dem1_5 and l_dem1_6 to logic
    logic.connect(&l_dem1_3.outport, logic.inport[0]);
    logic.connect(&l_dem2_3.outport, logic.inport[1]);

    // connect l_dem2_1 and l_dem2_2 to multiplier
    multiplier.connect(&l_dem1_4.outport, multiplier.inport[0]);
    multiplier.connect(&l_dem2_4.outport, multiplier.inport[1]);

    // connect l_dem2_3 and l_dem2_4 to divider
    divider.connect(&l_dem1_5.outport, divider.inport[0]);
    divider.connect(&l_dem2_5.outport, divider.inport[1]);

    // connect l_dem2_5 and l_dem2_6 to comparator
    comparator.connect(&l_dem1_6.outport, comparator.inport[0]);
    comparator.connect(&l_dem2_6.outport, comparator.inport[1]);

    // connect l_dem1_7 to two's complement
    twos_complement.connect(&l_dem1_7.outport, twos_complement.inport[0]);


    la1.connect(&adder.outport);
    la2.connect(&shifter.outport);
    la3.connect(&logic.outport);
    la4.connect(&multiplier.outport);
    la5.connect(&divider.outport);
    la6.connect(&comparator.outport);
    la7.connect(&twos_complement.outport);

    // connect lalu mux to adder, shifter, logic, twos_complement, multiplier, divider, comparator
    lalu_mux.connect(&la1.outport, lalu_mux.inport[0]);
    lalu_mux.connect(&la2.outport, lalu_mux.inport[1]);
    lalu_mux.connect(&la3.outport, lalu_mux.inport[2]);
    lalu_mux.connect(&la4.outport, lalu_mux.inport[3]);
    lalu_mux.connect(&la5.outport, lalu_mux.inport[4]);
    lalu_mux.connect(&la6.outport, lalu_mux.inport[5]);
    lalu_mux.connect(&la7.outport, lalu_mux.inport[6]);
    
    // connect lalu mux to lalu latch
    lalu.connect(&lalu_mux.outport);

    // connect lalu latch to lalu demux
    lalu_dem.connect(&lalu.outport, lalu_dem.inport[0]);

    // architecture is now declared and connected.

    //DEBUGGING CODE
    register_file.registers[4] = 30;
    register_file.registers[3] = 2;

    int test_cycles = 0;
    long long a = 1;
    ifd.connect_signal(&a);
    opcode.connect_signal(&a); // ifd and opcode dont need control register
    bool start = true;
    
    while (true) { // should only pass first inputs, call do_functions, and recieve clocks. 
        // pass input to first devices (first device(s) in dependency chain) probably the PC to the fetch unit. 
        // if (test_cycles == 7) 
        //     std::cout << "here" << std::endl;
        fetcher.receive_clock();
        ifd.receive_clock();
        decoder.receive_clock();
        opcode.receive_clock();

        pc.outport+=4; // we need add4
    
        lookup.receive_clock();
        control_array.receive_clock();

        // assign contorl signals
        control_signal_t *ctr_sig;
        ctr_sig = control_array.outport;

        if (ctr_sig == NULL) { // HALT
            std::cout << "HALT" << std::endl;
            std::cout << "Num cycles: " << test_cycles << std::endl;
            break;
        }

        // assign bitfields of ctr_sig to respective devices
        lrd.connect_signal(&ctr_sig->lrd);
        lrs.connect_signal(&ctr_sig->lrs);
        lrt.connect_signal(&ctr_sig->lrt);
        ll.connect_signal(&ctr_sig->ll);
        ll_dem.connect(&ctr_sig->ll_dem, ll_dem.ctrlport);
        lrd_dem.connect(&ctr_sig->lrd_dem, lrd_dem.ctrlport);
        lrt_dem.connect(&ctr_sig->lrt_dem, lrt_dem.ctrlport);
        lrf1_mux.connect(&ctr_sig->lrf1_mux, lrf1_mux.ctrlport);
        lrf2_mux.connect(&ctr_sig->lrf2_mux, lrf2_mux.ctrlport);
        lrf_1.connect_signal(&ctr_sig->lrf1);
        lrf_2.connect_signal(&ctr_sig->lrf2);
        register_file.connect(&ctr_sig->register_file, register_file.ctrlport);
        lrf_out_1.connect_signal(&ctr_sig->lrf_out_1);
        lrf_out_2.connect_signal(&ctr_sig->lrf_out_2);
        l1_mux.connect(&ctr_sig->l1_mux, l1_mux.ctrlport);
        l2_mux.connect(&ctr_sig->l2_mux, l2_mux.ctrlport);
        l1.connect_signal(&ctr_sig->l1);
        l2.connect_signal(&ctr_sig->l2);
        l1_dem.connect(&ctr_sig->l1_dem, l1_dem.ctrlport);
        l_dem1_1.connect_signal(&ctr_sig->l_dem1_1);
        l_dem1_2.connect_signal(&ctr_sig->l_dem1_2);
        l_dem1_3.connect_signal(&ctr_sig->l_dem1_3);
        l_dem1_4.connect_signal(&ctr_sig->l_dem1_4);
        l_dem1_5.connect_signal(&ctr_sig->l_dem1_5);
        l_dem1_6.connect_signal(&ctr_sig->l_dem1_6);
        l_dem1_7.connect_signal(&ctr_sig->l_dem1_7);
        l2_dem.connect(&ctr_sig->l2_dem, l2_dem.ctrlport);
        l_dem2_1.connect_signal(&ctr_sig->l_dem2_1);
        l_dem2_2.connect_signal(&ctr_sig->l_dem2_2);    
        l_dem2_3.connect_signal(&ctr_sig->l_dem2_3);
        l_dem2_4.connect_signal(&ctr_sig->l_dem2_4);
        l_dem2_5.connect_signal(&ctr_sig->l_dem2_5);
        l_dem2_6.connect_signal(&ctr_sig->l_dem2_6);
        la1.connect_signal(&ctr_sig->la1);
        la2.connect_signal(&ctr_sig->la2);
        la3.connect_signal(&ctr_sig->la3);
        la4.connect_signal(&ctr_sig->la4);
        la5.connect_signal(&ctr_sig->la5);
        la6.connect_signal(&ctr_sig->la6);
        la7.connect_signal(&ctr_sig->la7);
        lalu_mux.connect(&ctr_sig->lalu_mux, lalu_mux.ctrlport);
        lalu.connect_signal(&ctr_sig->lalu);
        lalu_dem.connect(&ctr_sig->lalu_dem, lalu_dem.ctrlport);
        shifter.connect(&ctr_sig->shifter, shifter.ctrlport);
        logic.connect(&ctr_sig->logic, logic.ctrlport);

        // horizontal code = parallel/independent 
        // ==================================
        lalu.receive_clock();
        lalu_dem.receive_clock();
        // ==================================

        la1.receive_clock(); la2.receive_clock(); la3.receive_clock(); la4.receive_clock(); la5.receive_clock(); la6.receive_clock(); la7.receive_clock();
        lalu_mux.receive_clock();
        
        // ==================================

        l_dem1_1.receive_clock(); l_dem1_2.receive_clock(); l_dem1_3.receive_clock(); l_dem1_4.receive_clock(); l_dem1_5.receive_clock(); l_dem1_6.receive_clock(); l_dem1_7.receive_clock();
        l_dem2_1.receive_clock(); l_dem2_2.receive_clock(); l_dem2_3.receive_clock(); l_dem2_4.receive_clock(); l_dem2_5.receive_clock(); l_dem2_6.receive_clock();
        adder.receive_clock(); shifter.receive_clock(); logic.receive_clock(); twos_complement.receive_clock(); multiplier.receive_clock(); divider.receive_clock(); comparator.receive_clock();

        // ==================================

        l1.receive_clock(); l2.receive_clock();
        l1_dem.receive_clock(); l2_dem.receive_clock();

        // ==================================

        lrf_out_1.receive_clock(); lrf_out_2.receive_clock();

        // ==================================

        lrf_1.receive_clock(); lrf_2.receive_clock();
        register_file.receive_clock();

        // ==================================

        lrd.receive_clock(); lrs.receive_clock(); lrt.receive_clock(); ll.receive_clock();
        lrd_dem.receive_clock(); lrt_dem.receive_clock(); ll_dem.receive_clock(); // not sure about ll_dem
        lrf1_mux.receive_clock(); lrf2_mux.receive_clock();
        l1_mux.receive_clock(); l2_mux.receive_clock();

        std::cout << "lrf1_mux output: " << lrf1_mux.outport << std::endl;
        std::cout << "lrf2_mux output: " << lrf2_mux.outport << std::endl;

        // horizontal execution/code = parallel/independent 
        // ==================================
        // lalu.receive_clock();
        // lalu_dem.receive_clock();
        // // ==================================

        // la1.receive_clock(); la2.receive_clock(); la3.receive_clock(); la4.receive_clock(); la5.receive_clock(); la6.receive_clock(); la7.receive_clock();
        // lalu_mux.receive_clock();
        
        // // ==================================

        // l_dem1_1.receive_clock(); l_dem1_2.receive_clock(); l_dem1_3.receive_clock(); l_dem1_4.receive_clock(); l_dem1_5.receive_clock(); l_dem1_6.receive_clock(); l_dem1_7.receive_clock();
        // l_dem2_1.receive_clock(); l_dem2_2.receive_clock(); l_dem2_3.receive_clock(); l_dem2_4.receive_clock(); l_dem2_5.receive_clock(); l_dem2_6.receive_clock();
        // adder.receive_clock(); shifter.receive_clock(); logic.receive_clock(); twos_complement.receive_clock(); multiplier.receive_clock(); divider.receive_clock(); comparator.receive_clock();

        // // ==================================

        // l1.receive_clock(); l2.receive_clock();
        // l1_dem.receive_clock(); l2_dem.receive_clock();

        // // ==================================

        // lrf_out_1.receive_clock(); lrf_out_2.receive_clock();
        // l1_mux.receive_clock(); l2_mux.receive_clock();

        // // ==================================

        // lrf_1.receive_clock(); lrf_2.receive_clock();
        // register_file.receive_clock();

        // // ==================================

        // lrd.receive_clock(); lrs.receive_clock(); lrt.receive_clock(); ll.receive_clock();
        // lrd_dem.receive_clock(); lrt_dem.receive_clock(); ll_dem.receive_clock(); // not sure about ll_dem
        // lrf1_mux.receive_clock(); lrf2_mux.receive_clock();


        // std::cout << "lrf1_mux output: " << lrf1_mux.outport << std::endl;
        // std::cout << "lrf2_mux output: " << lrf2_mux.outport << std::endl;

        test_cycles++;

        // //DEBUGGING CODE
        printf("----------------\n");
        for (int i = 0; i < 32; i++) {
            printf("registers[%d]: %lld\n", i, register_file.registers[i]);
        }
        printf("----------------\n");

        // if (control_array.control_registers.size() == 0) { // finished instructions 
        //     std::cout << "Num cycles: " << test_cycles << std::endl;
        // }
    }

    // // //DEBUGGING CODE
    // printf("----------------\n");
    // for (int i = 0; i < 32; i++) {
    //     printf("registers[%d]: %lld\n", i, register_file.registers[i]);
    // }
    // printf("----------------\n");

    return 0;
}