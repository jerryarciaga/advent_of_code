#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    int floor = 0;
    char instr;

    if(input == NULL) {
        printf("%20s", "File not found.\n");
        return 1;
    }
    else {
        do{
            instr = getc(input);
            if((int)instr == 40) 
                ++floor;
            else if((int)instr == 41)
                --floor;
            else;
            printf("%7s %3d\n", "Floor:", floor);
        } while(instr != EOF);
    }

    return 0;
}
