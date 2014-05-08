//
//  check_type_inst.cpp
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#include "check_type_inst.h"

bool check_R_Type1(std::string inst)
{
    // If it is one of the two return true
    bool istype = false;
    if (inst == "sll" || inst == "srl") {
        istype = true;
    }
    return istype;
}

bool check_R_Type2(std::string inst)
{
    // If it is jr return true
    bool istype = false;
    if (inst == "jr") {
        istype = true;
    }
    return istype;
}


bool check_I_Type1(std::string inst)
{
    // If it is one of these 7 return true
    bool istype = false;
    if (inst == "addi" || inst == "addiu"||
        inst == "andi" || inst == "ori"||
        inst == "slti" || inst == "sltui"||
        inst == "lui") {
        istype = true;
    }
    return istype;
}

bool check_I_Type2(std::string inst)
{
    // If it is one of the two instructions return true.
    bool istype = false;
    if(inst == "beq" || inst == "bne")
    {
        istype = true;
    }
    return istype;
}