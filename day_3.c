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
        int trees = 0;

        // We know that the first space is open; no need to be extra
        fgets(line, 255, input);
        line[strlen(line)-1] ='\0';

        for(int i = 0; i < lines; ++i) {
            // Extract line from file
            fgets(line,255, input);
            line[strlen(line)-1] = '\0';

            // Go right three times, then read next line/down one time
            right += 3;
            trees += (line[right % strlen(line)] == '#') ? 1 : 0;
        }
        printf("Number of trees encountered: %d", trees);
        fclose(input);
    }

    return 0;
}
