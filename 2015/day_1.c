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
        /* PART I*/
        do{
            instr = getc(input);
            if((int)instr == 40) 
                ++floor;
            else if((int)instr == 41)
                --floor;
            else;
        } while(instr != EOF);
        printf("%25s %4d\n", "Part I: Floor", floor);
        fclose(input);

        /* PART II */
        int basement = 0;
        input = fopen("input.txt", "r");
        do{
            ++basement;
            instr = getc(input);
            if(instr == '\(')
                ++floor;
            else if((int)instr == 41)
                --floor;
            else;
        }while(instr != EOF && floor != -1);
        printf("%25s %4d\n", "Part II: Position", basement);
        fclose(input);
    }

    return 0;
}
