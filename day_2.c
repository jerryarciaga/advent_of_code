#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // Open file
    FILE *file = fopen("input.txt", "r");
    int lines = 1000; // wc -l input.txt

    if(file == NULL) {
        fprintf(stderr, "Error: No file selected");
        return 1;
    }

    // Set up variables for reading password file
    int min, max, ch_count;
    char letter;
    char password[255];
    int valid_passwords = 0;
    
    // Then read said file into variables
    for(int i = 0; i<lines; i++) {
        fscanf(file, "%d-%d %c: ", &min, &max, &letter);
        fgets(password, 255, file);
        
        // Start counting characters in a given password
        ch_count = 0;
        for(int i = 0; i < strlen(password); ++i)
            ch_count += (password[i] == letter) ? 1 : 0;
        
        // Rule check: password must contain letter within constraints
        valid_passwords += (ch_count >= min && ch_count <= max) ? 1 : 0;
    }

    // Print number of valid passwords
    printf("Number of valid passwords: %d\n", valid_passwords);
    fclose(file);


    
    return 0;
}
