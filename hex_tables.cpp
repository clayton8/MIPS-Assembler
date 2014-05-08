//
//  hex_tables.cpp
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#include "hex_tables.h"


std::string Hash_Opcodes(std::string key)
{
    // WIll return INVALID if the operation does not match
    std::string opc;
    if (key == "add") {
        opc = "000000";
    }
    else if(key == "addi" )
    {
        opc = "001000";
    }
    else if(key == "addiu" )
    {
        opc = "001001";
    }
    else if(key == "addu" )
    {
        opc = "000000";
    }
    else if(key == "and" )
    {
        opc = "000000";
    }
    else if(key == "andi" )
    {
        opc = "001100";
    }
    else if(key == "beq" )
    {
        opc = "000100";
    }
    else if(key == "bne" )
    {
        opc = "000101";
    }
    else if(key == "jr" )
    {
        opc = "000000";
    }
    else if(key == "lbu" )
    {
        opc = "100100";
    }
    else if(key == "lhu" )
    {
        opc = "100101";
    }
    else if(key == "ll" )
    {
        opc = "110000";
    }
    else if(key == "lui" )
    {
        opc = "001111";
    }
    else if(key == "lw" )
    {
        opc = "100011";
    }
    else if(key == "nor" )
    {
        opc = "000000";
    }
    else if(key == "or" )
    {
        opc = "000000";
    }
    else if(key == "ori" )
    {
        opc = "001101";
    }
    else if(key == "slt" )
    {
        opc = "000000";
    }
    else if(key == "slti" )
    {
        opc = "001010";
    }
    else if(key == "sltiu" )
    {
        opc = "001011";
    }
    else if(key == "sltu" )
    {
        opc = "000000";
    }
    else if(key == "sll" )
    {
        opc = "000000";
    }
    else if(key == "srl" )
    {
        opc = "000000";
    }
    else if(key == "sb" )
    {
        opc = "101000";
    }
    else if(key == "sc" )
    {
        opc = "111000";
    }
    else if(key == "sh" )
    {
        opc = "101001";
    }
    else if(key == "sw" )
    {
        opc = "101011";
    }
    else if(key == "sub" )
    {
        opc = "000000";
    }
    else if(key == "subu" )
    {
        opc = "000000";
    }
    else
    {
        opc = "INVALID";
    }
    
    return opc;
    
}

std::string Hash_Func(std::string key)
{
    // Will return invalid if the operation does not match one of these
    std::string fun;
    if (key == "add"){
        fun = "100000";
    }
    else if(key == "addu" )
    {
        fun = "100001";
    }
    else if(key == "and" )
    {
        fun = "100100";
    }
    else if(key == "jr" )
    {
        fun = "001000";
    }
    else if(key == "nor" )
    {
        fun = "100111";
    }
    else if(key == "or" )
    {
        fun = "100101";
    }
    else if(key == "slt" )
    {
        fun = "101010";
    }
    else if(key == "sltu" )
    {
        fun = "101011";
    }
    else if(key == "sll" )
    {
        fun = "000000";
    }
    else if(key == "srl" )
    {
        fun = "000010";
    }
    else if(key == "sub" )
    {
        fun = "100010";
    }
    else if(key == "subu" )
    {
        fun = "100011";
    }
    else
    {
        fun = "INVALID";
    }
    return fun;
    
}


std::string Hash_Reg(std::string key){
    // The ($R) is for load and storing to data registers and istead of deleting the () I created another register.
    // SO it checks for the register without surrounding () and with surrounding ().
    // Returns INVALID if it doesn't match.
    std::string number;
    if (key == "$zero" || key == "($zero)")
        number = "00000";
    else if(key == "$at" || key == "($at)")
        number = "00001";
    else if(key == "$v0" || key == "($v0)")
        number = "00010";
    else if(key == "$v1" || key == "($v1)")
        number = "00011";
    else if(key == "$a0" || key == "($a0)")
        number = "00100";
    else if(key == "$a1" || key == "($a1)")
        number = "00101";
    else if(key == "$a2" || key == "($a2)")
        number = "00110";
    else if(key == "$a3" || key == "($a3)")
        number = "00111";
    else if(key == "$t0" || key == "($t0)")
        number = "01000";
    else if(key == "$t1" || key == "($t1)")
        number = "01001";
    else if(key == "$t2" || key == "($t2)")
        number = "01010";
    else if(key == "$t3" || key == "($t3)")
        number = "01011";
    else if(key == "$t4" || key == "($t4)")
        number = "01100";
    else if(key == "$t5" || key == "($t5)")
        number = "01101";
    else if(key == "$t6" || key == "($t6)")
        number = "01110";
    else if(key == "$t7" || key == "($t7)")
        number = "01111";
    else if(key == "$s0" || key == "($s0)")
        number = "10000";
    else if(key == "$s1" || key == "($s1)")
        number = "10001";
    else if(key == "$s2" || key == "($s2)")
        number = "10010";
    else if(key == "$s3" || key == "($s3)")
        number = "10011";
    else if(key == "$s4" || key == "($s4)")
        number = "10100";
    else if(key == "$s5" || key == "($s5)")
        number = "10101";
    else if(key == "$s6" || key == "($s6)")
        number = "10110";
    else if(key == "$s7" || key == "($s7)")
        number = "10111";
    else if(key == "$t8" || key == "($t8)")
        number = "11000";
    else if(key == "$t9" || key == "($t9)")
        number = "11001";
    else if(key == "$k0" || key == "($k0)")
        number = "11010";
    else if(key == "$k1" || key == "($k1)")
        number = "11011";
    else if(key == "$gp" || key == "($gp)")
        number = "11100";
    else if(key == "$sp" || key == "($sp)")
        number = "11101";
    else if(key == "$fp" || key == "($fp)")
        number = "11110";
    else if(key == "$ra" || key == "($ra)")
        number = "11111";
    else
        number = "INVALID";

return number;
}