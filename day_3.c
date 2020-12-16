#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tree_count(char *inputFile, int right, int lines);

int main() {
    char *inputFile = "input.txt";
    int lines = 323; // wc -l input.txt
    int trees = 0;

    /* PART ONE */
    trees = tree_count(inputFile, 3, lines);
    printf("Number of trees encountered (Part 1): %d\n", trees);
    /* END PART ONE */
    
    /* PART TWO */
    unsigned long final_answer = 1;
    final_answer *= (unsigned long)tree_count(inputFile, 1, lines);
    final_answer *= (unsigned long)tree_count(inputFile, 3, lines);
    final_answer *= (unsigned long)tree_count(inputFile, 5, lines);
    final_answer *= (unsigned long)tree_count(inputFile, 7, lines);
    
    // Special Case: Right 1, down 2
    FILE *input = fopen(inputFile, "r");
    int right = 0;
    char line[255];
    for(int i = 0; i <= (lines/2) + 2; ++i) {
        right++;
        fgets(line, 255, input);
        line[strlen(line)-1] = '\0';
        fgets(line, 255, input);
        line[strlen(line)-1] = '\0';

        trees += (line[right % strlen(line)] == '#');
    }
    final_answer *= trees;
    printf("Number of trees encountered (Part 2): %lu\n", final_answer);
    fclose(input);
    /* END PART TWO */

    return 0;
}

// Function assumes down = 1
int tree_count(char *inputFile, int right, int lines) {
    FILE *input = fopen(inputFile, "r");
    int trees;

    if(inputFile == NULL) {
        fprintf(stderr, "File not recognized.\n");
        return -1;
    }
    else {
        char line[255];
        int index = 0;
        trees = 0;

        fgets(line, 255, input);
        for(int i = 0; i < lines; ++i) {
            fgets(line, 255, input);
            line[strlen(line)-1] = '\0';

            index += right;
            trees += (line[index % strlen(line)] == '#');
        }
        
        fclose(input);
    }

    return trees;
}
