//
//  converting.cpp
//  myAssembler
//
//  Created by Clayton Kuchta on 2/24/14.
//  Copyright (c) 2014 Clayton Kuchta. All rights reserved.
//

#include "converting.h"

std::string int_to_bin5(const int num)
{
    std::string s = std::bitset< 5 >( num ).to_string();
    return s;
}

std::string int_to_bin16(const int num)
{
    std::string s = std::bitset< 16 >( num ).to_string();
    return s;
}

// This splits the 32 bits into 8 sets of 4 bits and converts
// each into a single hex value and then combines them all into one string.
std::string bin_to_hex_32_bit(std::string string)
{

    std::string final_out;
    // Get the first four digits
    std::string temp = string.substr(0,4);
    // Convert and set to final_out
    final_out = bin_to_hex_4_bit(temp);
    
    // Get second four digits
    temp = string.substr(4,4);
    // Append them onto the the output.
    final_out.append(bin_to_hex_4_bit(temp));
    
    temp = string.substr(8,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    temp = string.substr(12,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    temp = string.substr(16,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    temp = string.substr(20,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    temp = string.substr(24,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    temp = string.substr(28,4);
    final_out.append(bin_to_hex_4_bit(temp));

    
    
    
    
    
    return final_out;
}

// This converts a 4 bit binary into a single hex value
// if it doesn't match it returns INVALID
std::string bin_to_hex_4_bit(std::string string)
{
    std::string ret_str;
    if (string == "0000") {
        ret_str = "0";
    }
    else if(string == "0001")
    {
        ret_str = "1";
    }
    else if(string == "0010")
    {
        ret_str = "2";
    }
    else if(string == "0011")
    {
        ret_str = "3";
    }
    else if(string == "0100")
    {
        ret_str = "4";
    }
    else if(string == "0101")
    {
        ret_str = "5";
    }
    else if(string == "0110")
    {
        ret_str = "6";
    }
    else if(string == "0111")
    {
        ret_str = "7";
    }
    else if(string == "1000")
    {
        ret_str = "8";
    }
    else if(string == "1001")
    {
        ret_str = "9";
    }
    else if(string == "1010")
    {
        ret_str = "a";
    }
    else if(string == "1011")
    {
        ret_str = "b";
    }
    else if(string == "1100")
    {
        ret_str = "c";
    }
    else if(string == "1101")
    {
        ret_str = "d";
    }
    else if(string == "1110")
    {
        ret_str = "e";
    }
    else if(string == "1111")
    {
        ret_str = "f";
    }
    else
    {
        ret_str = "INVALID";
    }

    return ret_str;
    
}