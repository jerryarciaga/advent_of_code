#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input;
    int lines = 323; // wc -l input.txt
    
    /* PART ONE */
    // Open the file
    input = fopen("input.txt", "r");
    if(input == NULL) {
        fprintf(stderr, "Error: File not found\n");
        return 1;
    }
    else {
        char line[255];
        int right = 0;
        int down = 0;

        // We know that the first space is open; no need to be extra
        for(int i = 0; i < lines; ++i) {
            //Extract line from file
            fgets(line, 255, input);
            line[strlen(line)-1] ='\0';
            
        }
        fclose(input);
    }

    return 0;
}
