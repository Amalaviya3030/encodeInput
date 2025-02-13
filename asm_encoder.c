#include <stdio.h>
#include "../inc/encodeInput.h"

/*
 * FUNCTION: encodeASM
 * DESCRIPTION: This function eill read the input file and then convert it into asm format and then
                an output file will be dispalyed.
 * PARAMETERS: in - input file pointer, out- output file pointer
 * RETURNS: none
 */

void encodeASM(FILE* in, FILE* out) {
    unsigned char buffer[16];
    int count; //storing the data from the file

    while ((count = fread(buffer, 1, 16, in)) > 0) { //looping through the file, reading it and then prinitng the data
        fprintf(out, "dc.b ");
        for (int i = 0; i < count; i++) {
            fprintf(out, "$%02X%s", buffer[i], (i < count - 1) ? ", " : "\n");
        }
    }
}
