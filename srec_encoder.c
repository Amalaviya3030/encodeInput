#include <stdio.h>
#include "../inc/encodeInput.h"

void encodeSREC(FILE* in, FILE* out) {
    unsigned char buffer[16];
    int address = 0x0000;
    int count, checksum;

    fprintf(out, "S00E0000555454414D2D41524F5241D1\n"); // "UTTAM-ARORA" in ASCII-Hex
}