//
//  converting.h
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#ifndef __myAssembler__converting__
#define __myAssembler__converting__

#include <iostream>

// Converts the integer into a 5 bit string
// 5 -> 00101
std::string int_to_bin5(const int num);

// Converts an integer into a 16 bit string similar to function above
std::string int_to_bin16(const int num);

// Converts a 32 bit string into hex string
// 00000000000000000000000000000000 -> 00000000
std::string bin_to_hex_32_bit(std::string string);

// Converts a 4 bit string into singel hex string
// 1111 -> f
std::string bin_to_hex_4_bit(std::string string);

#endif /* defined(__myAssembler__converting__) */
