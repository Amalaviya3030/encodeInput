#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/encodeInput.h"

int main(int argc, char* argv[]) {
    char* inputFile = NULL, * outputFile = NULL;
    int srecFormat = 0; //to make sure that if srec format is chosen

    for (int i = 1; i < argc; i++) { //loop through the arguments
        if (strncmp(argv[i], "-i", 2) == 0) {
            inputFile = argv[i] + 2; //this is for checking if the argument that is given is an input file
        }
        else if (strncmp(argv[i], "-o", 2) == 0) {
            outputFile = argv[i] + 2; // this will do the same for output file
        }
        else if (strcmp(argv[i], "-srec") == 0) {
            srecFormat = 1; // this will check if the given argument is in srec format and also make sure we need it in srec
        }
        else if (strcmp(argv[i], "-h") == 0) {
            printf("Usage: encodeInput -i<inputfile> -o<outputfile> [-srec] [-h]\n");
            return 0; //this will print out the info
        }
        else {
            printf("Invalid option: %s\n", argv[i]); //if its incorrect error message will be shown
            return 1;
        }
    }

    if (!inputFile) { //if there is no input file then the error message is shown
        printf("Error: No input file specified\n");
        return 1;
    }

    if (!outputFile) { //if srec format is given then adding .srec format otherwise asm
        outputFile = srecFormat ? strcat(inputFile, ".srec") : strcat(inputFile, ".asm");
    }

    FILE* in = fopen(inputFile, "rb"); //file will be opened in bin mode
    if (!in) {
        printf("Error: Cannot open input file\n");
        return 1;
    }

    FILE* out = fopen(outputFile, "w"); //writing into the file here
    if (!out) {
        printf("Error: Cannot create output file\n");
        fclose(in);
        return 1;
    }

    if (srecFormat) //this will call out the function related to the chosen format
        encodeSREC(in, out);
    else
        encodeASM(in, out);

    fclose(in); //closing the files
    fclose(out);
    return 0;
}
