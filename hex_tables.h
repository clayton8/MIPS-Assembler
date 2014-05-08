//
//  hex_tables.h
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#ifndef __myAssembler__hex_tables__
#define __myAssembler__hex_tables__

#include <iostream>

// Returns the opcode according to instruction name: INVALID is returned if it does not match
std::string Hash_Opcodes(std::string key);

// Returns the function according to instruction name: INVALID is returned if it does not match
std::string Hash_Func(std::string key);

// Returns the register value in binary according to register name: INVALID is returned if it does not match
std::string Hash_Reg(std::string key);

#endif /* defined(__myAssembler__hex_tables__) */
