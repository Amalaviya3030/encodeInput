#include <stdio.h>
#include "../inc/encodeInput.h"

void encodeSREC(FILE* in, FILE* out) {
    unsigned char buffer[16];
    int address = 0x0000;
    int count, checksum;

    fprintf(out, "S00E0000555454414D2D41524F5241D1\n"); // "UTTAM-ARORA" in ASCII-Hex

    while ((count = fread(buffer, 1, 16, in)) > 0) {
        checksum = count + (address >> 8) + (address & 0xFF);

        fprintf(out, "S1%02X%04X", count + 3, address);
        for (int i = 0; i < count; i++) {
            fprintf(out, "%02X", buffer[i]);
            checksum += buffer[i];
        }

        checksum = (~checksum) & 0xFF;
        fprintf(out, "%02X\n", checksum);
        address += 16;
    }

    fprintf(out, "S503%04XFA\n", address / 16);
    fprintf(out, "S9030000FC\n");
}