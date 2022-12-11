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
#include "input.hh"
#include "output.hh"
#include <iostream>
#include <bitset>

int main () {

    // declare all devices in Execute unit
    Multiplexer16 pc_mux;
    Demultiplexer16 pc_dem;
    Multiplexer16 address_mux;
    Loadstore loadstore("code");
    Demultiplexer16 load_dem;

    InstructionDecode decoder;
    // InstructionFetch fetcher("code");
    Lookup lookup;
    ControlArray control_array;
    Demultiplexer16 lrd_dem;
    Demultiplexer16 lrs_dem;    
    Demultiplexer16 lrt_dem;
    Demultiplexer16 ll_dem;
    Multiplexer16 lrf1_mux;
    Multiplexer16 lrf2_mux;
    RegisterFile register_file;
    Demultiplexer16 lrf_out_1_dem;
    Demultiplexer16 lrf_out_2_dem;
    Multiplexer16 l1_mux;
    Multiplexer16 l2_mux;
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
    Demultiplexer16 lalu_dem;
    Input input_device;
    Output output_device;

    /* 
    each device has a latch connected to it, so we need to first define the first latches in the chain
    (and assign a value to them later in the loop)
    */

    Latch pc;
    pc.outport = 0;
    Latch l_add4_out;
    Latch l_pc_add4;
    Latch l_pc_ls_add;
    Latch l_pc_l1;
    Latch l_ls_address;
    Latch l_load_data;
    Latch l_load_data_lrf1;
    Latch ifd;
    Latch lrd;
    Latch lrd_lrf1;
    Latch lrd_lrf2;
    Latch lrs;
    Latch lrs_lrf1;
    Latch lrs_lrf2;
    Latch lrt;
    Latch lrt_lrf1;
    Latch lrt_lrf2;
    Latch ll;
    Latch lim;
    Latch ll_l1;
    Latch ll_l2;
    Latch opcode;
    Latch l_in_lrf1;
    Latch lrf_1;
    Latch lrf_2;
    Latch lrf_out_1;
    Latch lrf_out_2;
    Latch lrf_out_1_out;
    Latch lrf_out_1_ls;
    Latch lrf_out_1_pc;
    Latch lrf_out_1_l1;
    Latch lrf_out_1_l2;
    Latch lrf_out_1_in;
    Latch lrf_out_1_lrf1;
    Latch lrf_out_2_l2;
    Latch lrf_out_2_out;
    Latch l1;
    Latch l2;
    Latch l_dem1_1;
    Latch l_dem1_2;
    Latch l_dem1_3;
    Latch l_dem1_4;
    Latch l_dem1_5;
    Latch l_dem1_6;
    Latch l_dem1_7;
    Latch l_dem1_8;
    Latch l_dem1_9;
    Latch l_dem2_1;
    Latch l_dem2_2;
    Latch l_dem2_3;
    Latch l_dem2_4;
    Latch l_dem2_5;
    Latch l_dem2_6;
    Latch l_dem2_7;
    Latch l_dem2_8;
    Latch la1;
    Latch la2;
    Latch la3;
    Latch la4;
    Latch la5;
    Latch la6;
    Latch la7;
    Latch la8;
    Latch la9;
    Latch lalu;
    Latch lalu_l2;
    Latch lalu_lrf1;
    Latch lalu_pc;
    Latch lalu_ls_add;
    Latch lalu_lut;


    /*
    .
    .
    .
    */

    /* connect the Latches with the ports of the devices */
    // connect add4 to to l_pc_add4 latch
    add4.connect(&l_pc_add4.outport, add4.inport[0]);

    // connect l_add4_out to add4 outport
    l_add4_out.connect(&add4.outport);

    // connect pc_mux to l_add4_out latch
    pc_mux.connect(&l_add4_out.outport, pc_mux.inport[0]);
    pc_mux.connect(&lalu_pc.outport, pc_mux.inport[1]);
    pc_mux.connect(&lrf_out_1_pc.outport, pc_mux.inport[2]);

    // connect pc latch to pc_mux 
    pc.connect(&pc_mux.outport);

    // connect pc_dem to pc 
    pc_dem.connect(&pc.outport, pc_dem.inport[0]);

    // connect latches to pc_dem
    l_pc_add4.connect(&pc_dem.outport[0]);
    l_pc_ls_add.connect(&pc_dem.outport[1]);
    l_pc_l1.connect(&pc_dem.outport[2]);

    // connect address_mux to latches l_pc_ls_add and lalu_ls
    address_mux.connect(&lalu_ls_add.outport, address_mux.inport[0]);
    address_mux.connect(&l_pc_ls_add.outport, address_mux.inport[1]);

    // connect l_ls_address to address_mux
    l_ls_address.connect(&address_mux.outport);

    // connect l/s unit to l_ls_address latch and lrf_out_1_ls latch
    loadstore.connect(&l_ls_address.outport, loadstore.inport[0]);
    loadstore.connect(&lrf_out_1_ls.outport, loadstore.inport[1]);

    // connect l_load_data to loadstore outport
    l_load_data.connect(&loadstore.outport[0]);

    // connect load_dem to l_load_data latch
    load_dem.connect(&l_load_data.outport, load_dem.inport[0]);

    // connect ifd latch to load_dem outport
    // ifd.connect(&load_dem.outport[0]); uncomment then

    // connect l_laod_data_lrf1 to load_dem outport
    l_load_data_lrf1.connect(&load_dem.outport[1]);

    //PC Latch -> Instruction Fetch
    // fetcher.connect(&pc.outport, fetcher.inport[0]);

    //Instruction Fetch -> IFD Latch
    ifd.connect(&load_dem.outport[0]);

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

    // connect lrs_dem to lrs latch
    lrs_dem.connect(&lrs.outport, lrs_dem.inport[0]);

    // connect ll_dem port 0 to ll latch
    ll_dem.connect(&ll.outport, ll_dem.inport[0]);

    // connect lrd_dem to following latches
    lrd_lrf1.connect(&lrd_dem.outport[0]);
    lrd_lrf2.connect(&lrd_dem.outport[1]);

    // connect lrs_dem to following latches
    lrs_lrf1.connect(&lrs_dem.outport[0]);
    lrs_lrf2.connect(&lrs_dem.outport[1]);

    // connect lrt_dem to following latches
    lrt_lrf1.connect(&lrt_dem.outport[0]);
    lrt_lrf2.connect(&lrt_dem.outport[1]);

    // connect ll_dem to following latches
    ll_l1.connect(&ll_dem.outport[0]);
    ll_l2.connect(&ll_dem.outport[1]);

    // connect lookup port 0 to opcode latch
    lookup.connect(&opcode.outport, lookup.inport[0]);

    // connect lookup to control array
    control_array.connect_array(&lookup.outport, control_array.inport[0]);


    // conect lrf1_mux
    lrf1_mux.connect(&l_in_lrf1.outport, lrf1_mux.inport[0]); // for input
    lrf1_mux.connect(&lrf_out_1_lrf1.outport, lrf1_mux.inport[1]);
    lrf1_mux.connect(&l_load_data_lrf1.outport, lrf1_mux.inport[2]);
    lrf1_mux.connect(&lrd_lrf1.outport, lrf1_mux.inport[3]);
    lrf1_mux.connect(&lrs_lrf1.outport, lrf1_mux.inport[4]);
    lrf1_mux.connect(&lrt_lrf1.outport, lrf1_mux.inport[5]);
    lrf1_mux.connect(&lalu_lrf1.outport, lrf1_mux.inport[6]);

    //connect lrf2_mux
    lrf2_mux.connect(&lrd_lrf2.outport, lrf2_mux.inport[0]);
    lrf2_mux.connect(&lrs_lrf2.outport, lrf2_mux.inport[1]);
    lrf2_mux.connect(&lrt_lrf2.outport, lrf2_mux.inport[2]);

    l_in_lrf1.connect(&input_device.outport);
    output_device.connect(&lrf_out_1_out.outport, output_device.inport[0]);

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

    // connect lrf_out_1 to following demux
    lrf_out_1_dem.connect(&lrf_out_1.outport, lrf_out_1_dem.inport[0]);
    lrf_out_2_dem.connect(&lrf_out_2.outport, lrf_out_2_dem.inport[0]);

    // connect lrf_out_1_dem to following latches
    lrf_out_1_out.connect(&lrf_out_1_dem.outport[0]); // not connected yet
    lrf_out_1_ls.connect(&lrf_out_1_dem.outport[1]);
    lrf_out_1_pc.connect(&lrf_out_1_dem.outport[2]);
    lrf_out_1_l1.connect(&lrf_out_1_dem.outport[3]);
    lrf_out_1_lrf1.connect(&lrf_out_1_dem.outport[4]);
    lrf_out_1_l2.connect(&lrf_out_1_dem.outport[5]);
    lrf_out_1_in.connect(&lrf_out_1_dem.outport[6]);
    // lrf_out_1_l2.connect(&lrf_out_1_dem.outport[1]);
    // connect rest later

    // connect lrf_out_2 to following latch
    lrf_out_2_l2.connect(&lrf_out_2_dem.outport[0]);
    lrf_out_2_out.connect(&lrf_out_2_dem.outport[1]);

    // connect l1 mux to lrf_out_1 and ll_dem
    l1_mux.connect(&ll_l1.outport, l1_mux.inport[0]);
    l1_mux.connect(&lrf_out_1_l1.outport, l1_mux.inport[1]);
    l1_mux.connect(&l_pc_l1.outport, l1_mux.inport[2]); // lim still not connected

    // connect l2 mux to lrf_out_2 and ll_dem and lalu_dem
    l2_mux.connect(&lrf_out_1_l2.outport, l2_mux.inport[0]);
    l2_mux.connect(&ll_l2.outport, l2_mux.inport[1]);
    l2_mux.connect(&lrf_out_2_l2.outport, l2_mux.inport[2]);
    l2_mux.connect(&lim.outport, l2_mux.inport[3]); // lim still not connected
    l2_mux.connect(&lalu_l2.outport, l2_mux.inport[4]);

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
    l_dem1_8.connect(&l1_dem.outport[7]);
    l_dem1_9.connect(&l1_dem.outport[8]);


    // connect l_dem2_1 - l_dem2_6 to l2_dem output
    l_dem2_1.connect(&l2_dem.outport[0]);
    l_dem2_2.connect(&l2_dem.outport[1]);
    l_dem2_3.connect(&l2_dem.outport[2]);
    l_dem2_4.connect(&l2_dem.outport[3]);
    l_dem2_5.connect(&l2_dem.outport[4]);
    l_dem2_6.connect(&l2_dem.outport[5]);
    l_dem2_7.connect(&l2_dem.outport[6]);
    l_dem2_8.connect(&l2_dem.outport[7]);

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
    // la8
    // la9

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

    lalu_l2.connect(&lalu_dem.outport[0]);
    lalu_lrf1.connect(&lalu_dem.outport[1]);
    lalu_pc.connect(&lalu_dem.outport[2]);
    lalu_ls_add.connect(&lalu_dem.outport[3]);
    lalu_lut.connect(&lalu_dem.outport[4]); // not connected yet

    // architecture is now declared and connected.

    //DEBUGGING CODE
    register_file.registers[4] = 30;
    register_file.registers[3] = 2;

    int test_cycles = 0;
    bool start = true;

    // long long one = 1;
    // long long zero = 0;

    // pc.connect_signal(&one);
    // pc_dem.connect(&one, pc_dem.ctrlport);
    // l_pc_ls_add.connect_signal(&one);
    // address_mux.connect(&one, address_mux.ctrlport);
    // l_ls_address.connect_signal(&one);
    // loadstore.connect(&one, loadstore.ctrlport);
    // l_load_data.connect_signal(&one);
    // load_dem.connect(&zero, load_dem.ctrlport);
    // ifd.connect_signal(&one);
    // decoder.connect(&one, decoder.ctrlport);
    // opcode.connect_signal(&one);
    // lookup.connect(&one, lookup.ctrlport);

    // // this part before the while loop is to run the first 6 cycles that will fetch the first instruciton 
    // // and get the first control signal for the execute part

    // pc.receive_clock();
    // pc_dem.receive_clock();
    // l_pc_ls_add.receive_clock();
    // address_mux.receive_clock();
    // l_ls_address.receive_clock();
    // loadstore.receive_clock();
    // l_load_data.receive_clock();
    // load_dem.receive_clock();
    // ifd.receive_clock();
    // decoder.receive_clock();
    // opcode.receive_clock();
    // lookup.receive_clock();

    control_array.receive_clock();
    control_signal_t *ctr_sig;
    ctr_sig = control_array.outport;
    
    
    while (true) { // should only pass first inputs, call do_functions, and recieve clocks. 
        // pass input to first devices (first device(s) in dependency chain) probably the PC to the fetch unit. 
        // if (test_cycles == 7) 
        //     std::cout << "here" << std::endl;
        // fetcher.receive_clock();
        // pc.receive_clock();
        // // pc_dem






        // ifd.receive_clock();
        // decoder.receive_clock();
        // opcode.receive_clock();

        // pc.outport+=4; // we need add4
    
        // lookup.receive_clock();
        // control_array.receive_clock();

        // // assign contorl signals
        // control_signal_t *ctr_sig;
        // ctr_sig = control_array.outport;

        if (ctr_sig == NULL) { // HALT
            std::cout << "HALT" << std::endl;
            std::cout << "Num cycles: " << test_cycles << std::endl;
            break;
        }

        // assign bitfields of ctr_sig to respective devices
        ifd.connect_signal(ctr_sig->ifd);
        opcode.connect_signal(ctr_sig->opcode);
        decoder.connect_signal(ctr_sig->ifd);
        lookup.connect_signal(ctr_sig->opcode);
        lrd.connect_signal(ctr_sig->lrd);
        lrs.connect_signal(ctr_sig->lrs);
        lrt.connect_signal(ctr_sig->lrt);
        ll.connect_signal(ctr_sig->ll);
        // lim here
        lrd_dem.connect_signal(ctr_sig->lrd_dem);
        lrs_dem.connect_signal(ctr_sig->lrs_dem);
        lrt_dem.connect_signal(ctr_sig->lrt_dem);
        ll_dem.connect_signal(ctr_sig->ll_dem);
        lrd_lrf1.connect_signal(ctr_sig->lrd_lrf1);
        lrd_lrf2.connect_signal(ctr_sig->lrd_lrf2);
        lrs_lrf1.connect_signal(ctr_sig->lrs_lrf1);
        lrs_lrf2.connect_signal(ctr_sig->lrs_lrf2);
        lrt_lrf1.connect_signal(ctr_sig->lrt_lrf1);
        lrt_lrf2.connect_signal(ctr_sig->lrt_lrf2);
        ll_l1.connect_signal(ctr_sig->ll_l1);
        ll_l2.connect_signal(ctr_sig->ll_l2);
        lrf1_mux.connect_signal(ctr_sig->lrf1_mux);
        lrf2_mux.connect_signal(ctr_sig->lrf2_mux);
        lrf_1.connect_signal(ctr_sig->lrf1);
        lrf_2.connect_signal(ctr_sig->lrf2);
        register_file.connect_signal(ctr_sig->register_file);
        lrf_out_1.connect_signal(ctr_sig->lrf_out_1);
        lrf_out_2.connect_signal(ctr_sig->lrf_out_2);
        lrf_out_1_dem.connect_signal(ctr_sig->lrf_out_1_dem);
        lrf_out_2_dem.connect_signal(ctr_sig->lrf_out_2_dem);
        lrf_out_1_l1.connect_signal(ctr_sig->lrf_out_1_l1);
        lrf_out_2_l2.connect_signal(ctr_sig->lrf_out_2_l2);
        l1_mux.connect_signal(ctr_sig->l1_mux);
        l2_mux.connect_signal(ctr_sig->l2_mux);
        l1.connect_signal(ctr_sig->l1);
        l2.connect_signal(ctr_sig->l2);
        l1_dem.connect_signal(ctr_sig->l1_dem);
        l2_dem.connect_signal(ctr_sig->l2_dem);
        l_dem1_1.connect_signal(ctr_sig->l_dem1_1);
        l_dem1_2.connect_signal(ctr_sig->l_dem1_2);
        l_dem1_3.connect_signal(ctr_sig->l_dem1_3);
        l_dem1_4.connect_signal(ctr_sig->l_dem1_4);
        l_dem1_5.connect_signal(ctr_sig->l_dem1_5);
        l_dem1_6.connect_signal(ctr_sig->l_dem1_6);
        l_dem1_7.connect_signal(ctr_sig->l_dem1_7);
        l_dem1_8.connect_signal(ctr_sig->l_dem1_8);
        l_dem1_9.connect_signal(ctr_sig->l_dem1_9);
        l_dem2_1.connect_signal(ctr_sig->l_dem2_1);
        l_dem2_2.connect_signal(ctr_sig->l_dem2_2);    
        l_dem2_3.connect_signal(ctr_sig->l_dem2_3);
        l_dem2_4.connect_signal(ctr_sig->l_dem2_4);
        l_dem2_5.connect_signal(ctr_sig->l_dem2_5);
        l_dem2_6.connect_signal(ctr_sig->l_dem2_6);
        l_dem2_7.connect_signal(ctr_sig->l_dem2_7);
        l_dem2_8.connect_signal(ctr_sig->l_dem2_8);
        shifter.connect_signal(ctr_sig->shifter);
        logic.connect_signal(ctr_sig->logic);
        la1.connect_signal(ctr_sig->la1);
        la2.connect_signal(ctr_sig->la2);
        la3.connect_signal(ctr_sig->la3);
        la4.connect_signal(ctr_sig->la4);
        la5.connect_signal(ctr_sig->la5);
        la6.connect_signal(ctr_sig->la6);
        la7.connect_signal(ctr_sig->la7);
        la8.connect_signal(ctr_sig->la8);
        la9.connect_signal(ctr_sig->la9);
        lalu_mux.connect_signal(ctr_sig->lalu_mux);
        lalu.connect_signal(ctr_sig->lalu);
        lalu_dem.connect_signal(ctr_sig->lalu_dem);
        lalu_l2.connect_signal(ctr_sig->lalu_l2);
        lalu_lrf1.connect_signal(ctr_sig->lalu_lrf1);
        lalu_pc.connect_signal(ctr_sig->lalu_pc);

        // continue in same order of declaration
        lalu_ls_add.connect_signal(ctr_sig->lalu_ls_add);
        lalu_lut.connect_signal(ctr_sig->lalu_lut);
        pc_mux.connect_signal(ctr_sig->pc_mux);
        pc.connect_signal(ctr_sig->pc);
        pc_dem.connect_signal(ctr_sig->pc_dem);
        l_pc_add4.connect_signal(ctr_sig->l_pc_add4);
        l_pc_ls_add.connect_signal(ctr_sig->l_pc_ls_add);
        l_pc_l1.connect_signal(ctr_sig->l_pc_l1);
        l_add4_out.connect_signal(ctr_sig->l_add4_out);
        address_mux.connect_signal(ctr_sig->address_mux);
        l_ls_address.connect_signal(ctr_sig->l_ls_address);
        loadstore.connect_signal(ctr_sig->loadstore);
        l_load_data.connect_signal(ctr_sig->l_load_data);
        l_load_data.connect_signal(ctr_sig->l_load_data);
        load_dem.connect_signal(ctr_sig->load_dem);
        l_load_data_lrf1.connect_signal(ctr_sig->l_load_data_lrf1);
        lrf_out_1_in.connect_signal(ctr_sig->lrf_out_1_in);
        l_in_lrf1.connect_signal(ctr_sig->l_in_lrf1);
        lrf_out_2_out.connect_signal(ctr_sig->lrf_out_2_out);



        // ================================================
        lalu_l2.receive_clock(); lalu_lrf1.receive_clock(); 
        // ================================================
        lalu.receive_clock();
        lalu_dem.receive_clock();
        // ================================================
        la1.receive_clock(); la2.receive_clock(); la3.receive_clock(); la4.receive_clock(); la5.receive_clock(); la6.receive_clock(); la7.receive_clock();     
        lalu_mux.receive_clock();
        // ================================================
        l_dem1_1.receive_clock(); l_dem1_2.receive_clock(); l_dem1_3.receive_clock(); l_dem1_4.receive_clock(); l_dem1_5.receive_clock(); l_dem1_6.receive_clock(); l_dem1_7.receive_clock();
        l_dem2_1.receive_clock(); l_dem2_2.receive_clock(); l_dem2_3.receive_clock(); l_dem2_4.receive_clock(); l_dem2_5.receive_clock(); l_dem2_6.receive_clock();
        adder.receive_clock(); shifter.receive_clock(); logic.receive_clock(); twos_complement.receive_clock(); multiplier.receive_clock(); divider.receive_clock(); comparator.receive_clock();
        // ================================================
        l1.receive_clock(); l2.receive_clock();
        l1_dem.receive_clock(); l2_dem.receive_clock();
        // ================================================        
        lrf_out_1_l1.receive_clock(); lrf_out_2_l2.receive_clock();
        // ================================================
        lrf_out_1.receive_clock(); lrf_out_2.receive_clock();
        lrf_out_1_dem.receive_clock(); lrf_out_2_dem.receive_clock();
        // ================================================
        lrf_1.receive_clock(); lrf_2.receive_clock();
        register_file.receive_clock();
        // ================================================
        lrd_lrf1.receive_clock(); lrd_lrf2.receive_clock(); lrs_lrf1.receive_clock(); lrs_lrf2.receive_clock(); lrt_lrf1.receive_clock(); lrt_lrf2.receive_clock(); ll_l1.receive_clock(); ll_l2.receive_clock();
        lrf1_mux.receive_clock(); 
        lrf2_mux.receive_clock(); 
        l1_mux.receive_clock(); 
        l2_mux.receive_clock(); 
        // ================================================
        lrd.receive_clock(); lrs.receive_clock(); lrt.receive_clock(); ll.receive_clock();
        lrd_dem.receive_clock(); lrs_dem.receive_clock(); lrt_dem.receive_clock(); ll_dem.receive_clock();
        // ================================================
        opcode.receive_clock();
        lookup.receive_clock();
        control_array.receive_clock(); // will this overwrite signals? test
        // ================================================
        ifd.receive_clock();
        decoder.receive_clock();
        // ================================================
        l_load_data.receive_clock();
        load_dem.receive_clock();
        // ================================================
        l_ls_address.receive_clock();
        loadstore.receive_clock();
        // ================================================
        l_pc_add4.receive_clock(); l_pc_ls_add.receive_clock(); l_pc_l1.receive_clock();
        address_mux.receive_clock(); add4.receive_clock();
        // ================================================
        l_add4_out.receive_clock();
        pc_mux.receive_clock();
        // ================================================
        pc.receive_clock();
        pc_dem.receive_clock();
        // ================================================
        

        // std::cout << "lrf1_mux output: " << lrf1_mux.outport << std::endl;
        // std::cout << "lrf2_mux output: " << lrf2_mux.outport << std::endl;

        test_cycles++;
        ctr_sig = control_array.outport;

        // //DEBUGGING CODE
        printf("----------------\n");
        for (int i = 0; i < 32; i++) {
            printf("registers[%d]: %lld\n", i, register_file.registers[i]);
        }
        printf("----------------\n");

    }

    // // //DEBUGGING CODE
    // printf("----------------\n");
    // for (int i = 0; i < 32; i++) {
    //     printf("registers[%d]: %lld\n", i, register_file.registers[i]);
    // }
    // printf("----------------\n");

    return 0;
}