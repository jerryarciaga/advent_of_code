// TODO: Fix this whole code to get rid of duplicate outputs

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("input.txt", "r");
    
    if (file == NULL) {
        printf("Failed to open file");
        return 1;
    }
    else {
        int entries[200];
        unsigned long a, b, c;
        
        // Read file into array
        printf("%20s", "Reading input.txt...");
        for(int i=0; i<200; ++i)
            fscanf(file, "%d", entries + i);
        printf("%10s\n", "DONE");
        
        // Parse them numbers
        for(int i=0; i<200; ++i) {
            a = entries[i];
            for(int i=0; i<200; ++i) {
                b = entries[i];
                if(a + b == 2020) {
                    printf("Number found! %d\n", a * b);
                    break;
                }
            }
        }

        // Parse them numbers part 2
        for(int i=0; i<200; ++i) {
            a = entries[i];
            for(int i=0; i<200; ++i) {
                b = entries[i];
                for(int i=0; i<200; ++i) {
                    c = entries[i];
                    if(a + b + c == 2020){
                        printf("Number2 found! %lu\n", a * b * c);
                        break;
                    }
                }
            }
        }
    }
    
    printf("wtf\n");
    return 0;
}
