#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>

int main() {
  //Read code file
  std::ifstream rf("code.txt");
  if(!rf) {
      std::cout << "Cannot open file!" << std::endl;
      return 1;
  }

  //Write to binary file
  std::ofstream wf("code", std::ios::out | std::ios::binary);
  if(!wf) {
      std::cout << "Cannot open file!" << std::endl;
      return 1;
  }
  
  //Read line by line
  std::string instruction;
  while (getline(rf, instruction)) {
      //Split instruction to words
      std::istringstream words(instruction);
      std::string word;
      uint32_t machine_instruction = 0;
      if (words >> word) {
          //Convert each word to bits
          if (word == "add") {
              machine_instruction = (machine_instruction + 0b00000) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      if (words >> word) {
                          if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                              //r_s
                              machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                              if (words >> word) {
                                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                                      //r_t
                                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 12;
                                  } else {
                                      std::cout << "Invalid Instruction!";
                                      return 1;
                                  }
                              } else {
                                  std::cout << "Invalid Instruction!";
                                  return 1;
                              }
                          } else {
                              std::cout << "Invalid Instruction!";
                              return 1;
                          }
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "addi") {
              machine_instruction = (machine_instruction + 0b00001) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      machine_instruction = machine_instruction << 5;
                      machine_instruction = machine_instruction << 12;
                      if (words >> word) {
                          machine_instruction = (machine_instruction + stoi(word.substr(0,word.length())));
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "sub") {
              machine_instruction = (machine_instruction + 0b00010) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      if (words >> word) {
                          if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                              //r_s
                              machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                              if (words >> word) {
                                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                                      //r_t
                                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 12;
                                  } else {
                                      std::cout << "Invalid Instruction!";
                                      return 1;
                                  }
                              } else {
                                  std::cout << "Invalid Instruction!";
                                  return 1;
                              }
                          } else {
                              std::cout << "Invalid Instruction!";
                              return 1;
                          }
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "subi") {
              machine_instruction = (machine_instruction + 0b00011) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      machine_instruction = machine_instruction << 5;
                      machine_instruction = machine_instruction << 12;
                      if (words >> word) {
                          machine_instruction = (machine_instruction + stoi(word.substr(0,word.length())));
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "mul") {
              machine_instruction = (machine_instruction + 0b00100) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      if (words >> word) {
                          if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                              //r_s
                              machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                              if (words >> word) {
                                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                                      //r_t
                                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 12;
                                  } else {
                                      std::cout << "Invalid Instruction!";
                                      return 1;
                                  }
                              } else {
                                  std::cout << "Invalid Instruction!";
                                  return 1;
                              }
                          } else {
                              std::cout << "Invalid Instruction!";
                              return 1;
                          }
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "div") {
              machine_instruction = (machine_instruction + 0b00101) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      if (words >> word) {
                          if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                              //r_s
                              machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                              if (words >> word) {
                                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                                      //r_t
                                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 12;
                                  } else {
                                      std::cout << "Invalid Instruction!";
                                      return 1;
                                  }
                              } else {
                                  std::cout << "Invalid Instruction!";
                                  return 1;
                              }
                          } else {
                              std::cout << "Invalid Instruction!";
                              return 1;
                          }
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "out") {
              machine_instruction = (machine_instruction + 0b11110) << 5;
              if (words >> word) {
                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                      //r_d
                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                      if (words >> word) {
                          if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                              //r_s
                              machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 5;
                              if (words >> word) {
                                  if (word.length() > 1 && word.length() <= 3 && word[0] == 'r') {
                                      //r_t
                                      machine_instruction = (machine_instruction + stoi(word.substr(1,word.length() - 1))) << 12;
                                  } else {
                                      std::cout << "Invalid Instruction!";
                                      return 1;
                                  }
                              } else {
                                  std::cout << "Invalid Instruction!";
                                  return 1;
                              }
                          } else {
                              std::cout << "Invalid Instruction!";
                              return 1;
                          }
                      } else {
                          std::cout << "Invalid Instruction!";
                          return 1;
                      }
                  } else {
                      std::cout << "Invalid Instruction!";
                      return 1;
                  }
              }
          } else if (word == "halt") {
              machine_instruction = (machine_instruction + 0b11111) << 27;
          } else {
              std::cout << "Invalid Instruction!";
              return 1;
          }
      }
      // uint32_t test = 0b00001000000000000000000000000001;
      // std::cout << test << std::endl;
      // std::cout << machine_instruction << std::endl;
      wf.write((char *) &machine_instruction, sizeof(uint32_t));
  }
  wf.close();
  return 0;
}