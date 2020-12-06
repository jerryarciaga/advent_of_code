#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Open file
    FILE *file;
    int lines = 1000; // wc -l input.txt
    char password[255];
    char letter;
    
    /* PART ONE */
    // Set up variables for reading password file
    int min, max, ch_count;
    int valid_passwords = 0;
    
    // Then read said file into variables
    file = fopen("input.txt", "r");
    if(file == NULL) {
        fprintf(stderr, "Error: No file selected\n");
        return 1;
    }
    else {
        for(int i = 0; i < lines; i++) {
            fscanf(file, "%d-%d %c: ", &min, &max, &letter);
            fgets(password, 255, file);
            
            // Start counting characters in a given password
            ch_count = 0;
            for(int i = 0; i < strlen(password); ++i)
                ch_count += (password[i] == letter) ? 1 : 0;
            
            // Rule check: password must contain letter within constraints
            valid_passwords += (ch_count >= min && ch_count <= max) ? 1 : 0;
        }
    }

    // Print number of valid passwords
    printf("Number of valid passwords: %d\n", valid_passwords);
    fclose(file);
    /* END PART ONE */

    /* PART TWO */
    // Set up variables for reading file
    int index1, index2;
    valid_passwords = 0;
    int matches = 0;

    // Open file one more time
    file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: No file selected\n");
        return 1;
    }
    else {
        for(int i = 0; i < lines; i++) {
            fscanf(file, "%d-%d %c: ", &index1, &index2, &letter);
            fgets(password, 255, file);
            
            // printf("%s\n", password);
            // Check letters in index1 and index2 (remember 1-index)
            matches = 0;
            matches += (letter == password[index1-1]) ? 1 : 0;
            matches += (letter == password[index2-1]) ? 1 : 0;
            valid_passwords += (matches == 1) ? 1: 0;
        }
    }
    
    // Print number of valid passwords
    printf("Number of valid passwords: %d\n", valid_passwords);
    fclose(file);

    return 0;
}
