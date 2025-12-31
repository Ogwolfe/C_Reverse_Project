#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *string;
    struct Node *next;
};



int main(int argc, char** argv){

    FILE *input = stdin, *output = stdout;

    //Error: Too many args
    if(argc > 3){
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    //Input file provided
    if(argc > 1){
        input = fopen(argv[1], "r");
        if(input == NULL){ 
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }
    }

    //Output file also provided
    if(argc > 2){
        if(strcmp(argv[1], argv[2]) == 0){
            fprintf(stderr, "Input and output file must differ\n");
            fclose(input);
            exit(1);
        }

        output = fopen(argv[2], "w");
        if(output == NULL){
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            fclose(input);
            exit(1);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}