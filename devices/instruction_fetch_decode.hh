#ifndef INSTRUCTIONFETCHDECODE_HH
#define INSTRUCTIONFETCHDECODE_HH
#include "device.hh"
#include <iostream>
#include <fstream>

class InstructionFetchDecode : public Device {
public:
    instruction_t instr;

    InstructionFetchDecode(char const* filename) {
      //Open the binary file of instructions

      instructionFile.open(filename, std::ios::out | std::ios::binary);
      if(!instructionFile) {
        std::cout << "Cannot open instruction file" << std::endl;
        result = -1;
        return;
      }
    }
    ~InstructionFetchDecode() {
      instructionFile.close();
    }
    void receive_clock() {outLatch.value = result;}
    void do_function(uint32_t PC) {
      /* --- Instruction Fetch and Decode --- */
      
      //Seek to the program counter's value
      instructionFile.seekg(PC, std::ios::beg);

      //Read the opcode, r_d, r_s, r_t, literal to the instruction struct.
      instructionFile.read((char *) &instr, sizeof(instruction_t));
      
      /* --- Control Signals --- */
      
      //TODO:

      result = 0;
    }
    void do_function() {}
    void connect(int port_id, Latch l) {}

    Latch outLatch;
private:
    long long result;

    std::ifstream instructionFile;
    

};

#endif