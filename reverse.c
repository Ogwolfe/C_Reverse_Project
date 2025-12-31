#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char *str;
    size_t len;
    struct Node *next;
};

struct Node *Head = NULL;

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

    char *current_line = NULL;
    size_t line_len = 0;
    ssize_t num_read;
    while((num_read = getline(&current_line, &line_len, input)) != -1){
        struct Node *p = malloc(sizeof(struct Node));
        if(!p){
            fprintf(stderr, "malloc failed\n");
            fclose(input);
            fclose(output);
            exit(1);
        }

        p->str = malloc(num_read + 1);
        strcpy(p->str, current_line);
        p->len = num_read;

        //Base case: first element
        if(!Head)   p->next = NULL;

        else    p->next = Head;

        Head = p;
    }

    free(current_line);

    while(Head){
        struct Node *p = Head->next;
        fwrite(Head->str, Head->len, 1, output);
        free(Head->str);
        free(Head);
        Head = p;
    }

    fclose(input);
    fclose(output);
    return 0;
}