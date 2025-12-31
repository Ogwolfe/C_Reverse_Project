#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

    FILE *input = NULL, *output = NULL;

    if(argc > 3){
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    if(argc == 3){
        if(strcmp(argv[1], argv[2]) == 0){
            fprintf(stderr, "Input and output file must differ\n");
            exit(1);
        }

        input = fopen(argv[1], "r");
        if(input == NULL){ 
            fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
            exit(1);
        }

        output = fopen(argv[2], "w");
        if(output == NULL){
            fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
            exit(1);
        }

        fclose(input);
        fclose(output);
    }



    
    return 0;
}