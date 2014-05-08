#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>

#include "exceptions.h"
#include "lexer.h"
#include "util.h"

#include "hex_tables.h"
#include "converting.h"
#include "check_type_inst.h"

std::string read_file(const std::string& name) {
    std::ifstream file(name);
    if (!file.is_open()) {
        std::string error = "Could not open file: ";
        error += name;
        throw std::runtime_error(error);
    }
    std::stringstream stream;
    stream << file.rdbuf();
    return std::move(stream.str());
}

int main(int argc, char** argv) {
    // Adjusting -- argv[0] is always filename.
    --argc;
    ++argv;
    
    if (argc == 0) {
        std::cerr << "Need a file" << std::endl;
        return 1;
    }
    
    for (int i = 0; i < argc; ++i) {
        std::string asmName(argv[i]);
        
        if (!util::ends_with_subseq(asmName, std::string(".asm"))) {
            std::cerr << "Need a valid file name (that ends in .asm)" << std::endl;
            std::cerr << "(Bad name: " << asmName << ")" << std::endl;
            return 1;
        }
        
        // 4 is len(".asm")
        auto length = asmName.size() - string_length(".asm");
        std::string baseName(asmName.begin(), asmName.begin() + length);
        std::string objName = baseName + ".obj";
        
        std::string current_line;
        std::string opcode;
        std::string rs;
        std::string rt;
        std::string rd;
        std::string shamt;
        std::string funct;
        std::string immediate;
        std::string op_code_binary;
        std::string op_code_hex;
        std::vector<std::string> all_machine_code;
        
        stdin;
        
        try {
            auto text = read_file(asmName);
            try {
                auto lexed = lexer::analyze(text);		// Parses the entire file and returns a vector of instructions
                
                for (int i =0; i<lexed.size(); i++){
                    
                    opcode = Hash_Opcodes(lexed[i].name);
                    
                    ////////////// CHECK FOR name is correct ////////////////
                    if(opcode == "INVALID" || (opcode != "000000" && lexed[i].args.size() != 3))
                    {
                        throw_bad_asm(lexed[i].line);
                    }
                    
                    
                    
                    ///////////// R TYPE ////////////////
                    if(opcode == "000000")
                    {
                        // ***** Fill in funct
                        funct = Hash_Func(lexed[i].name);
                        // Make sure the name is correct and correct number of arguments
                        if(funct == "INVALID" || (funct != "001000" && lexed[i].args.size() != 3) || (funct == "001000" && lexed[i].args.size() != 1))
                        {
                            throw_bad_asm(lexed[i].line, "Invalid label on line: ");
                        }
                    
                        
                        //////////// If it is a shift right or left. FIll in info
                        if (check_R_Type1(lexed[i].name))
                        {
                            // Check to see if the shant is a number
                            if (!lexed[i].args[2].type == lexer::token::Integer ||
                                Hash_Reg(lexed[i].args[0].string()) == "INVALID" ||
                                Hash_Reg(lexed[i].args[1].string()) == "INVALID")
                            {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            
                            shamt = int_to_bin5(lexed[i].args[2].integer());
                            rd = Hash_Reg(lexed[i].args[0].string());
                            rt = Hash_Reg(lexed[i].args[1].string());
                            rs = "00000";
                            
                            
                        }
                        /////// Check for jr
                        else if (check_R_Type2(lexed[i].name))
                        {
                            // Bad register name
                            if (Hash_Reg(lexed[i].args[0].string()) == "INVALID") {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            rs = Hash_Reg(lexed[i].args[0].string());
                            rt = "00000";
                            rd = "00000";
                            shamt = "00000";
                        }
                        else
                        {
                            // Check to make sure all the registers are valid
                            if (Hash_Reg(lexed[i].args[0].string()) == "INVALID" ||
                                Hash_Reg(lexed[i].args[1].string()) == "INVALID" ||
                                Hash_Reg(lexed[i].args[2].string()) == "INVALID")
                            {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            // FIll in all th registers
                            rs = Hash_Reg(lexed[i].args[1].string());
                            rt = Hash_Reg(lexed[i].args[2].string());
                            rd = Hash_Reg(lexed[i].args[0].string());
                            shamt = "00000";
                        }
                        
                        //******* Combining rt rs opcode rd shamt and function into one string ************//
                        // Put it all together in binary
                        op_code_binary = opcode + rs + rt+ rd+ shamt + funct;
                        // create the hex machine code
                        op_code_hex = bin_to_hex_32_bit(op_code_binary);
                        
                    
                    }
                    
                
                    
                    
                    /////////////////////// I TYPE///////////
                    else
                    {
                        
                        /////// If it is $rt $rs $immediant ***** ADDI
                        if (check_I_Type1(lexed[i].name)) {
                            if (Hash_Reg(lexed[i].args[0].string()) == "INVALID"||
                                Hash_Reg(lexed[i].args[1].string()) == "INVALID"||
                                lexed[i].args[2].type == lexer::token::String) {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            // FIll in values.
                            rs = Hash_Reg(lexed[i].args[1].string());
                            rt = Hash_Reg(lexed[i].args[0].string());
                            immediate = int_to_bin16(lexed[i].args[2].integer());
                        }
                        
                        
                        /////// If it is $rt, $rs, Lable/number ****** BNE BEQ
                        else if (check_I_Type2(lexed[i].name))
                        {
                            if (Hash_Reg(lexed[i].args[0].string()) == "INVALID"||
                                Hash_Reg(lexed[i].args[1].string()) == "INVALID") {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            rs = Hash_Reg(lexed[i].args[0].string());
                            rt = Hash_Reg(lexed[i].args[1].string());
                            
                            // if it is a label
                            if(lexed[i].args[2].type == lexer::token::String)
                            {
                                bool found_match = false;
                                // Find matching label
                                for (int n = 0; n < lexed.size(); n++) {
                                    if (lexed[n].labels.size() > 0 && lexed[n].labels[0] == lexed[i].args[2].string()) {
                                        found_match = true;
                                        int num =  lexed[n].line - lexed[i].line-1;
                                        immediate = int_to_bin16(num);
                                    }
                                }
                                // If not found then throw an exception
                                if (!found_match) {
                                    throw bad_label(lexed[i].line, lexed[i].args[2].string());
                                }
                            }
                            else
                            {
                                // If it is a integer then fill in the immediate
                                immediate = int_to_bin16(lexed[i].args[2].integer());
                            }
                            
                        }
                        
                        
                        ///////////////// All other types of I types
                        else
                        {
                            // Check to see if everyting is valid
                            if (Hash_Reg(lexed[i].args[0].string()) == "INVALID"||
                                Hash_Reg(lexed[i].args[2].string()) == "INVALID" ||
                                lexed[i].args[1].type == lexer::token::String)
                            {
                                throw_bad_asm(lexed[i].line, "Invalid value on line: ");
                            }
                            // Fill in the rt, rs and immediate
                            rt = Hash_Reg(lexed[i].args[0].string());
                            rs = Hash_Reg(lexed[i].args[2].string());
                            immediate = int_to_bin16(lexed[i].args[1].integer());
                        }
                        
                        //******* Combining rt rs opcode and immediate into one string ************//
                        // Put it all together in binary
                        op_code_binary = opcode + rs + rt + immediate;
                        // create the hex machine code
                        op_code_hex = bin_to_hex_32_bit(op_code_binary);
                        
                    }
                    
                    // Add the machin to the back of the vector
                    all_machine_code.push_back(op_code_hex);
                    
                }
                
            } catch(const bad_asm& e) {
                std::stringstream error;
                error << "Cannot assemble the assembly code at line " << e.line;
                throw std::runtime_error(error.str());
            } catch(const bad_label& e) {
                std::stringstream error;
                error << "Undefined label " << e.what() << " at line " << e.line;
                throw std::runtime_error(error.str());
            }
            
        } catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
            return 1;
        }
        
        // Create a file and then stream all the machine code to the file
        std::ofstream file;
        file.open("output.txt");
        for (int i = 0; i < all_machine_code.size(); i++) {
            file << all_machine_code[i] << std::endl;
        }
        file.close();
        
        
    }
    
    std::cout << std::endl << "SUCCESSFUL CONVERSION PRESS 'ENTER' TO EXIT PROGRAM." << std::endl;
    
    getchar();
    return 0;
}
