#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
    FILE *file = fopen("input.txt", "r");
    int lines = 1000; // wc -l input.txt
    
    int min, max, ch_count;
    char letter;
    char password;
    for(int i = 0; i<lines; i++) {
        fscanf(file, "%d-%d %s: %s\n", &min, &max, letter, password);
    }

    
    return 0;
}
