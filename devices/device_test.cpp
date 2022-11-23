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
#include "register_file.hh"
#include "mp_register_file.hh"
#include "control_array.hh"
#include "instruction_fetch.hh"
#include "instruction_decode.hh"
#include <iostream>
#include <bitset>
int main () {
    std::string truth;
    Latch inLatch0, inLatch1, inLatch3, inLatch4;
    Latch ctrlLatch;
    // Adder Test
    {
    std::cout<<"=================="<<std::endl<<"Adder Test"<<std::endl;
    Adder adder;
    // positive
    inLatch0.outport = 1;
    inLatch1.outport = 2;
    adder.connect(&inLatch0.outport, adder.inport[0]);
    adder.connect(&inLatch1.outport, adder.inport[1]);
    adder.receive_clock();
    truth = (adder.outport == 3)? " PASS" : " FAIL";
    std::cout << *adder.inport[0] << " + " << *adder.inport[1] <<  " = "  << adder.outport << truth << std::endl;
    //negative 
    inLatch0.outport = -1;
    inLatch1.outport = -2;
    adder.connect(&inLatch0.outport, adder.inport[0]);
    adder.connect(&inLatch1.outport, adder.inport[1]);
    adder.receive_clock();
    truth = (adder.outport == -3)? " PASS" : " FAIL";
    std::cout << *adder.inport[0] << " + " << *adder.inport[1] <<  " = "  << adder.outport << truth << std::endl;
    }
    // Add4 Test
    {
    std::cout<<"=================="<<std::endl<<"Add4 Test"<<std::endl;
    Add4 add4;
    // positive
    inLatch0.outport = 1;
    add4.connect(&inLatch0.outport, add4.inport[0]);
    add4.receive_clock();
    truth = (add4.outport == 5)? " PASS" : " FAIL";
    std::cout << *add4.inport[0] << " + " << 4 <<  " = "  << add4.outport << truth << std::endl;
    }

    // Divider Test
    {
    std::cout<<"=================="<<std::endl<<"Divider Test"<<std::endl;
    Divider divider;
    // positive
    inLatch0.outport = 8;
    inLatch1.outport = 3;
    divider.connect(&inLatch0.outport, divider.inport[0]);
    divider.connect(&inLatch1.outport, divider.inport[1]);
    for (int i = 0; i < 8; i++) {
        divider.receive_clock();
    }
    truth = (divider.outport == 2)? " PASS" : " FAIL";
    std::cout << *divider.inport[0] << " / " << *divider.inport[1] <<  " = "  << divider.outport << truth << std::endl;
    }

    // Comparator Test
    {
    std::cout<<"=================="<<std::endl<<"Comparator Test"<<std::endl;
    Comparator comparator;
    Latch inLatch0;
    Latch inLatch1;
    // Equal
    inLatch0.outport = 2;
    inLatch1.outport = 2;
    comparator.connect(&inLatch0.outport, comparator.inport[0]);
    comparator.connect(&inLatch1.outport, comparator.inport[1]);
    comparator.receive_clock();
    std::string truth = (comparator.outport == 0)? " PASS" : " FAIL";
    std::cout << *comparator.inport[0] << " = " << *comparator.inport[1] <<  " ? "  << comparator.outport << truth << std::endl;
    // Unequal
    inLatch0.outport = 2;
    inLatch1.outport = 3;
    comparator.connect(&inLatch0.outport, comparator.inport[0]);
    comparator.connect(&inLatch1.outport, comparator.inport[1]);
    comparator.receive_clock();
    truth = (comparator.outport == 1)? " PASS" : " FAIL";
    std::cout << *comparator.inport[0] << " = " << *comparator.inport[1] <<  " ? "  << comparator.outport << truth << std::endl;
    }

    // Two Complement Test
    {
    std::cout<<"=================="<<std::endl<<"Two Complement Test"<<std::endl;
    TwoComplement twoComplement;
    inLatch0.outport = 1024;
    twoComplement.connect(&inLatch0.outport, twoComplement.inport[0]);
    twoComplement.receive_clock();
    truth = (twoComplement.outport == -1024)? " PASS" : " FAIL";
    std::cout << *twoComplement.inport[0] << "'s binary complement = " << -1024 << truth << std::endl;
    }

    // Multiplier Test
    {
    std::cout<<"=================="<<std::endl<<"Multiplier Test"<<std::endl;
    Multiplier multiplier;
    inLatch0.outport = 2;
    inLatch1.outport = -3;
    multiplier.connect(&inLatch0.outport, multiplier.inport[0]);
    multiplier.connect(&inLatch1.outport, multiplier.inport[1]);
    for(int i = 0; i < 3; i++) {
        multiplier.receive_clock();
    }
    truth = (multiplier.outport == -6)? " PASS" : " FAIL";
    std::cout << *multiplier.inport[0] << " * " << *multiplier.inport[1] <<  " = "  << multiplier.outport << truth << std::endl;
    }

    // Logic Test
    {
    std::cout<<"=================="<<std::endl<<"Logic Test"<<std::endl;
    Logic logic;
    inLatch0.outport = 1;
    inLatch1.outport = 0;
    ctrlLatch.outport = 1; // AND
    logic.connect(&inLatch0.outport, logic.inport[0]);
    logic.connect(&inLatch1.outport, logic.inport[1]);
    logic.connect(&ctrlLatch.outport, logic.ctrlport);
    logic.receive_clock();
    truth = (logic.outport == 0)? " PASS" : " FAIL";
    std::cout << *logic.inport[0] << " AND " << *logic.inport[1] <<  " = "  << logic.outport << truth << std::endl;
    }

    // Shift Test
    {
    std::cout<<"=================="<<std::endl<<"Shift Test"<<std::endl;
    Shifter shifter;
    inLatch0.outport = 16;
    inLatch1.outport = 1;
    ctrlLatch.outport = 0; // Shift Right
    shifter.connect(&inLatch0.outport, shifter.inport[0]);
    shifter.connect(&inLatch1.outport, shifter.inport[1]);
    shifter.connect(&ctrlLatch.outport, shifter.ctrlport);
    shifter.receive_clock();
    truth = (shifter.outport == 8)? " PASS" : " FAIL";
    std::cout << *shifter.inport[0] << " >> " << *shifter.inport[1] <<  " = "  << shifter.outport << truth << std::endl;
    }

    //multiplexer test
    {
    std::cout<<"=================="<<std::endl<<"Multiplexer Test"<<std::endl;
    Multiplexer multiplexer;
    inLatch0.outport = 0;
    inLatch1.outport = 1;
    inLatch3.outport = 2;
    inLatch4.outport = 3;
    ctrlLatch.outport = 1; // select inport 1
    multiplexer.connect(&inLatch0.outport, multiplexer.inport[0]);
    multiplexer.connect(&inLatch1.outport, multiplexer.inport[1]);
    multiplexer.connect(&inLatch3.outport, multiplexer.inport[2]);
    multiplexer.connect(&inLatch4.outport, multiplexer.inport[3]);
    multiplexer.connect(&ctrlLatch.outport, multiplexer.ctrlport);
    multiplexer.receive_clock();
    truth = (multiplexer.outport == 1)? " PASS" : " FAIL";
    std::cout << "Multiplexer output = " << multiplexer.outport << truth << std::endl;
    }

    //multiplexer test
    {
    std::cout<<"=================="<<std::endl<<"Multiplexer Test"<<std::endl;
    Demultiplexer demultiplexer;
    inLatch0.outport = 3;
    ctrlLatch.outport = 17; // select inport 3
    demultiplexer.connect(&inLatch0.outport, demultiplexer.inport[0]);
    demultiplexer.connect(&ctrlLatch.outport, demultiplexer.ctrlport);
    demultiplexer.receive_clock();
    truth = (demultiplexer.outport[3] == 3)? " PASS" : " FAIL";
    std::cout << "Demultiplexer output = " << demultiplexer.outport[3] << truth << std::endl;    
    }

    // RegisterFile Tes
    {
    std::cout<<"=================="<<std::endl<<"RegisterFile Test"<<std::endl;
    RegisterFile registerFile;
    inLatch0.outport = 100;
    inLatch1.outport = 18;
    ctrlLatch.outport = 17; //Store 100 on reg[18]
    registerFile.connect(&inLatch0.outport, registerFile.inport[0]);
    registerFile.connect(&inLatch1.outport, registerFile.inport[1]);
    registerFile.connect(&ctrlLatch.outport, registerFile.ctrlport);
    registerFile.receive_clock();
    inLatch0.outport = 18;
    ctrlLatch.outport = 1; //Store 100 on reg[18]
    registerFile.receive_clock();
    truth = (registerFile.outport[0] == 100)? " PASS" : " FAIL";
    std::cout << "RegisterFile output = " << registerFile.outport[0] << truth << std::endl;
    }

    // MPRegisterFile Tes
    {
    std::cout<<"=================="<<std::endl<<"MPRegisterFile Test"<<std::endl;
    MPRegisterFile mpRegisterFile;
    inLatch0.outport = 100;
    inLatch1.outport = 18;
    ctrlLatch.outport = 17; //Store 100 on reg[18]
    mpRegisterFile.connect(&inLatch0.outport, mpRegisterFile.inport[0]);
    mpRegisterFile.connect(&inLatch1.outport, mpRegisterFile.inport[1]);
    mpRegisterFile.connect(&ctrlLatch.outport, mpRegisterFile.ctrlport);
    mpRegisterFile.receive_clock();
    inLatch0.outport = 18;
    ctrlLatch.outport = 1; //Store 100 on reg[18]
    mpRegisterFile.receive_clock();
    truth = (mpRegisterFile.outport[0] == 100)? " PASS" : " FAIL";
    std::cout << "MPRegisterFile output = " << mpRegisterFile.outport[0] << truth << std::endl;
    }

    // Instruction Fetch and Decode Test
    {
    std::cout<<"=================="<<std::endl<<"Instruction Fetch and Decode Test"<<std::endl;
    InstructionFetch if_unit("code");
    InstructionDecode id_unit;
    
    Latch pc_l;
    Latch ifd_l;
    Latch opcode_l;
    Latch register_d_l;
    Latch register_s_l;
    Latch register_t_l;
    Latch literal_l;

    //PC Latch -> Instruction Fetch
    if_unit.connect(&pc_l.outport, if_unit.inport[0]);

    //Instruction Fetch -> IFD Latch
    ifd_l.connect(&if_unit.outport);

    //IFD Latch -> Instruction Decode
    id_unit.connect(&ifd_l.outport, id_unit.inport[0]);

    //Instruction Decode -> opcode, register, and literal Latches
    opcode_l.connect(&id_unit.opcode);
    register_d_l.connect(&id_unit.register_d);
    register_s_l.connect(&id_unit.register_s);
    register_t_l.connect(&id_unit.register_t);
    literal_l.connect(&id_unit.literal);

    pc_l.outport = 0; // PC Value, read first instruction

    if_unit.receive_clock(); // Fetch the instruction
    ifd_l.receive_clock(); // Receive the results from IF
    id_unit.receive_clock(); // Receive the results from the latch
    opcode_l.receive_clock(); // Receive the opcode from the ID
    register_d_l.receive_clock(); // Receive the register from the ID
    register_s_l.receive_clock(); // Receive the register from the ID
    register_t_l.receive_clock(); // Receive the register from the ID
    literal_l.receive_clock(); // Receive the literal from the ID

    printf("Instruction Fetch and Decode output: \n1- opcode: %lld, r_d: %lld, r_s: %lld, r_t: %lld, literal: %lld\n",
    opcode_l.outport, register_d_l.outport, register_s_l.outport, register_t_l.outport,
    literal_l.outport);

    pc_l.outport = 4; // PC Value, read second instruction

    if_unit.receive_clock(); // Fetch the instruction
    ifd_l.receive_clock(); // Receive the results from IF
    id_unit.receive_clock(); // Receive the results from the latch
    opcode_l.receive_clock(); // Receive the opcode from the ID
    register_d_l.receive_clock(); // Receive the register from the ID
    register_s_l.receive_clock(); // Receive the register from the ID
    register_t_l.receive_clock(); // Receive the register from the ID
    literal_l.receive_clock(); // Receive the literal from the ID

    printf("2- opcode: %lld, r_d: %lld, r_s: %lld, r_t: %lld, literal: %lld\n",
    opcode_l.outport, register_d_l.outport, register_s_l.outport, register_t_l.outport,
    literal_l.outport);
    }

    // control_array Test
    {
    std::cout<<"=================="<<std::endl<<"ControlArray Test"<<std::endl;
    std::cout << " ControlArray Pending ..." << std::endl;
    }
    
    return 0;
}