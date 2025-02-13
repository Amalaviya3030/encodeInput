#include <stdio.h>
#include "../inc/encodeInput.h"

/*
 * FUNCTION: encodeSREC
 * DESCRIPTION: This function will read data from input file and convert it into srec
 * PARAMETERS: in, out
 * RETURNS: none
 */

void encodeSREC(FILE* in, FILE* out) {
    unsigned char buffer[16];
    int address = 0x0000;
    int count, checksum; // storing data and doing checksum calculation

    fprintf(out, "S00E0000555454414D2D41524F5241D1\n"); // "UTTAM-ARORA" in ASCII-Hex

    while ((count = fread(buffer, 1, 16, in)) > 0) {
        checksum = count + (address >> 8) + (address & 0xFF);

        fprintf(out, "S1%02X%04X", count + 3, address);
        for (int i = 0; i < count; i++) {
            fprintf(out, "%02X", buffer[i]);
            checksum += buffer[i]; //this writes each byte in the format and then add it to checksum
        }

        checksum = (~checksum) & 0xFF;
        fprintf(out, "%02X\n", checksum); //write the final value
        address += 16;
    }

    fprintf(out, "S503%04XFA\n", address / 16);
    fprintf(out, "S9030000FC\n");
}
