#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <map>
#include <bitset>

#define RD_RS_RT 0
#define RD_RS 1
#define RD_RS_L 2
#define RD_L_RS 3
#define RD_L 4
#define RD 5
#define L 6

/*
    Missing: floating point, and macros
*/

/*
Instruction Types Constants:
(0) r_d, r_s, r_t
(1) r_d, r_s
(2) r_d, r_s, L
(3) r_d, L, r_s
(4) r_d, L
(5) r_d
(6) L
*/

uint32_t interpret_operands(uint32_t instr, std::string instruction, int instrType)
{
    std::string word;
    std::istringstream line(instruction);
    line >> word;

    switch (instrType)
    {
    case RD_RS_RT:
        if (line >> word)
        {
            if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
            {
                // r_d
                instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                if (line >> word)
                {
                    if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                    {
                        // r_s
                        instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                        if (line >> word)
                        {
                            if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                            {
                                // r_t
                                instr = (instr + stoi(word.substr(1, word.length() - 1))) << 12;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
        break;
    case RD_RS:
        if (line >> word)
        {
            if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
            {
                // r_d
                instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                if (line >> word)
                {
                    if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                    {
                        // r_s
                        instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                        instr = instr << 12;
                    } else {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        } else {
            return 0;
        }
        break;
    case RD_RS_L:
        if (line >> word)
        {
            if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
            {
                // r_d
                instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                if (line >> word)
                {
                    if (word.length() > 6 && word[0] == '(' && word[1] == 'r')
                    {
                        //(r_s) && (Literal)
                        if (word[3] == ')')
                        {
                            //(r_s)
                            instr = (instr + stoi(word.substr(2, 3))) << 5;
                            instr = instr << 12;
                            if (word[4] == '(' && word[word.length() - 1] == ')')
                            {
                                // (Literal)
                                instr = (instr + (stoi(word.substr(5, word.length() - 1)) & 0b111111111111));
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else if (word[4] == ')')
                        {
                            //(r_s)
                            instr = (instr + stoi(word.substr(2, 4))) << 5;
                            instr = instr << 12;
                            if (word[5] == '(' && word[word.length() - 1] == ')')
                            {
                                // (Literal)
                                instr = (instr + (stoi(word.substr(6, word.length() - 1)) & 0b111111111111));
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;
        case RD_L_RS:
            uint32_t tempL;
            if (line >> word)
            {
                if (word.length() > 6 && word[0] == '(' && word[1] == 'r')
                {
                    //(r_d) && (Literal)
                    if (word[3] == ')')
                    {
                        //(r_d)
                        instr = (instr + stoi(word.substr(2, 3))) << 5;

                        if (word[4] == '(' && word[word.length() - 2] == ')')
                        {
                            // (Literal)
                            tempL = stoi(word.substr(5, word.length() - 2)) & 0b111111111111;

                            if (line >> word)
                            {
                                if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                                {
                                    // r_s
                                    instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                                    instr = instr << 12;
                                    instr = instr + tempL;
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else if (word[4] == ')')
                    {
                        //(r_d)
                        instr = (instr + stoi(word.substr(2, 4))) << 5;

                        if (word[5] == '(' && word[word.length() - 2] == ')')
                        {
                            // (Literal)
                            tempL = stoi(word.substr(6, word.length() - 2)) & 0b111111111111;

                            if (line >> word)
                            {
                                if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                                {
                                    // r_s
                                    instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                                    instr = instr << 12;
                                    instr = instr + tempL;
                                }
                                else
                                {
                                    return 0;
                                }
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;
        case RD_L:
            if (line >> word)
            {
                if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                {
                    // r_d
                    instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                    instr = instr << 5;
                    instr = instr << 12;
                    if (line >> word)
                    {
                        // Literal
                        instr = (instr + (stoi(word.substr(0, word.length())) & 0b111111111111));
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
            break;
        case RD:
            if (line >> word)
            {
                if (word.length() > 1 && word.length() <= 4 && word[0] == 'r')
                {
                    // r_d
                    instr = (instr + stoi(word.substr(1, word.length() - 1))) << 5;
                    instr = instr << 5;
                    instr = instr << 12;
                }
                else
                {
                    return 0;
                }
            }
            break;
        case L:
            if (line >> word)
            {
                // Literal
                instr = instr << 5;
                instr = instr << 5;
                instr = instr << 12;
                instr = (instr + (stoi(word.substr(0, word.length())) & 0b111111111111));
            }
            else
            {
                return 0;
            }
        default:
            break;
        }
    }
    
    return instr;
}

// Interprets a line of Tinker code. Then writes it to wf.
uint32_t interpret_line(std::string instruction)
{
    uint32_t instr = 0;
    std::string word;
    std::istringstream line(instruction);
    line >> word;

    std::map<std::string, int> opcodes;
    opcodes.insert(std::make_pair("add", 0x0));
    opcodes.insert(std::make_pair("addi", 0x1));
    opcodes.insert(std::make_pair("sub", 0x2));
    opcodes.insert(std::make_pair("subi", 0x3));
    opcodes.insert(std::make_pair("mul", 0x4));
    opcodes.insert(std::make_pair("div", 0x5));
    opcodes.insert(std::make_pair("and", 0x6));
    opcodes.insert(std::make_pair("or", 0x7));
    opcodes.insert(std::make_pair("xor", 0x8));
    opcodes.insert(std::make_pair("not", 0x9));
    opcodes.insert(std::make_pair("shftr", 0xa));
    opcodes.insert(std::make_pair("shftri", 0xb));
    opcodes.insert(std::make_pair("shftl", 0xc));
    opcodes.insert(std::make_pair("shftli", 0xd));
    opcodes.insert(std::make_pair("br", 0x0e));
    opcodes.insert(std::make_pair("brr", 0x0f)); // or 0x10. check the switch case
    opcodes.insert(std::make_pair("brnz", 0x11));
    opcodes.insert(std::make_pair("call", 0x12));
    opcodes.insert(std::make_pair("return", 0x13));
    opcodes.insert(std::make_pair("brgt", 0x14));
    opcodes.insert(std::make_pair("halt", 0x1f));
    opcodes.insert(std::make_pair("mov", 0x15)); // or 0x16, 0x18. check the switch case
    opcodes.insert(std::make_pair("movi", 0x17));
    opcodes.insert(std::make_pair("in", 0x1d));
    opcodes.insert(std::make_pair("out", 0x1e));

    switch (opcodes.find(word)->second)
    {
    case 0x0:
        // add
        instr = (instr + 0x0) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x1:
        // addi
        instr = (instr + 0x1) << 5;
        instr = interpret_operands(instr, instruction, RD_L);
        break;
    case 0x2:
        // sub
        instr = (instr + 0x2) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x3:
        // subi
        instr = (instr + 0x3) << 5;
        instr = interpret_operands(instr, instruction, RD_L);
        break;
    case 0x4:
        // mul
        instr = (instr + 0x4) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x5:
        // div
        instr = (instr + 0x5) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x6:
        // and
        instr = (instr + 0x6) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x7:
        // or
        instr = (instr + 0x7) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x8:
        // xor
        instr = (instr + 0x8) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x9:
        // not
        instr = (instr + 0x9) << 5;
        instr = interpret_operands(instr, instruction, RD_RS);
        break;
    case 0xa:
        // shftr
        instr = (instr + 0xa) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0xb:
        // shftri
        instr = (instr + 0xb) << 5;
        instr = interpret_operands(instr, instruction, RD_L);
        break;
    case 0xc:
        // shftl
        instr = (instr + 0xc) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0xd:
        // shftli
        instr = (instr + 0xd) << 5;
        instr = interpret_operands(instr, instruction, RD_L);
        break;
    case 0x0e:
        // br
        instr = (instr + 0x0e) << 5;
        instr = interpret_operands(instr, instruction, RD);
        break;
    case 0x0f:
        // Test for brr r_d
        instr = (instr + 0x0f) << 5;
        instr = interpret_operands(instr, instruction, RD);
        if (instr == 0)
        {
            // Try for brr L
            instr = (instr + 0x10) << 5;
            instr = interpret_operands(instr, instruction, L);
        }
        break;
    case 0x11:
        // brnz
        instr = (instr + 0x11) << 5;
        instr = interpret_operands(instr, instruction, RD_RS);
        break;
    case 0x12:
        // call
        instr = (instr + 0x12) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x13:
        // return
        instr = (instr + 0x13) << 27;
        break;
    case 0x14:
        // brgt
        instr = (instr + 0x14) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_RT);
        break;
    case 0x1f:
        // halt
        instr = (instr + 0x1f) << 27;
        break;
    case 0x15:
        // Test for mov r_d, (r_s)(L)
        instr = (instr + 0x15) << 5;
        instr = interpret_operands(instr, instruction, RD_RS_L);
        if (instr == 0)
        {
            // Try for mov r_d, r_s
            instr = (instr + 0x16) << 5;
            instr = interpret_operands(instr, instruction, RD_RS);
        }

        if (instr == 0)
        {
            // Try for mov (r_d)(L), r_s
            instr = (instr + 0x18) << 5;
            instr = interpret_operands(instr, instruction, RD_L_RS);
        }

        break;
    case 0x17:
        // Try for mov r_d, L
        instr = (instr + 0x17) << 5;
        instr = interpret_operands(instr, instruction, RD_L);
        break;
    case 0x1d:
        // int
        instr = (instr + 0x1d) << 5;
        instr = interpret_operands(instr, instruction, RD_RS);
        break;
    case 0x1e:
        // out
        instr = (instr + 0x1e) << 5;
        instr = interpret_operands(instr, instruction, RD_RS);
        break;
    // case "clr":
    //     //Macro for clr r_d = xor r_d, r_d, r_d
    // case "ld":
    //     //Macro for ld r_d, L
    // case "push":
    //     //Macro for push r_d
    // case "pop":
    //     //Macro for pop r_d
    default:
        std::cout << "Invalid/Unimplemented opcode!";
        return 0;
    }

    if (instr != 0)
    {
        return instr;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        std::cout << "Please provide a source file name as an argument" << std::endl;
        return 1;
    }

    // Read code file
    std::ifstream rf(argv[1]);
    if (!rf)
    {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }

    // Write to binary file
    std::ofstream wf("code", std::ios::out | std::ios::binary);
    if (!wf)
    {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }

    // Read line by line
    int i = 1;
    std::string instruction;
    while (getline(rf, instruction))
    {
        uint32_t instr = 0;
        if ((instr = interpret_line(instruction)) == 0)
        {
            std::cout << i << "- " << "Invalid operands!" << std::endl;
        }
        else
        {
            std::cout << i << "- " << std::bitset<32>(instr) << std::endl;
            wf.write((char *)&instr, sizeof(uint32_t));
        }
        i++;
    }
    wf.close();
    std::cout << "Assembled to 'code'" << std::endl;
    return 0;
}