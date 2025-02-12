#include <stdio.h>
#include "../inc/encodeInput.h"

void encodeASM(FILE* in, FILE* out) {
    unsigned char buffer[16];
    int count;

    while ((count = fread(buffer, 1, 16, in)) > 0) {
        fprintf(out, "dc.b ");
        for (int i = 0; i < count; i++) {
            fprintf(out, "$%02X%s", buffer[i], (i < count - 1) ? ", " : "\n");
        }
    }
}