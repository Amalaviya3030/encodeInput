#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encodeInput.h"

int main(int argc, char* argv[]) {
    char* inputFile = NULL, * outputFile = NULL;
    int srecFormat = 0;

    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], "-i", 2) == 0) {
            inputFile = argv[i] + 2;
        }
        else if (strncmp(argv[i], "-o", 2) == 0) {
            outputFile = argv[i] + 2;
        }
        else if (strcmp(argv[i], "-srec") == 0) {
            srecFormat = 1;
        }
        else if (strcmp(argv[i], "-h") == 0) {
            printf("Usage: encodeInput -i<inputfile> -o<outputfile> [-srec] [-h]\n");
            return 0;
        }
        else {
            printf("Invalid option: %s\n", argv[i]);
            return 1;
        }
    }