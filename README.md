Tile: MIPS Assembler
Creator: Clayton Kuchta

--

## Description

The project is a C++ project created inside xCode.

This will load a text file that contains mips instructions and convert
it into machine code.

Please see the ‘MIPS_Green_Sheet.pdf’ for what instructions it can
convert.This will assemble all the instruction in the core instruction set with the exception of:

- j 
- jal 

instructions.

The format for an input file is attached in ‘test_1.s’ and will output
in a file called: ‘output.txt’

The original project description is in Project1.docx

## Build

- ./myAssembler <input.txt>

- ‘Output.txt’
