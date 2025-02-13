/*
 * FILE: encodeInput.h
 * PROJECT: A02 - System Programming
 * PROGRAMMERS: Anchita Kakria, Uttam Arora, Aryan Malaviya
 * FIRST VERSION: 12 feb 2025
 * DESCRIPTION: This is the header file containing the function protoypes for
                encoding function binary files into srec and asm format. THese functions will change
                binary data into ASCII format.
 */


#ifndef ENCODE_INPUT_H
#define ENCODE_INPUT_H

void encodeSREC(FILE* in, FILE* out);
void encodeASM(FILE* in, FILE* out);

#endif
