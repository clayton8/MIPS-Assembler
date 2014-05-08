//
//  check_type_inst.h
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#ifndef __myAssembler__check_type_inst__
#define __myAssembler__check_type_inst__

#include <iostream>

// Checks to see if it is a logical shift instruction
bool check_R_Type1(std::string inst);

// Checks to see if it is the jr instruction
bool check_R_Type2(std::string inst);

// Checking to see if it is in the form
// rt, rs, immediate
bool check_I_Type1(std::string inst);

// Checks to see if it is a branching instruction
bool check_I_Type2(std::string inst);

#endif /* defined(__myAssembler__check_type_inst__) */
