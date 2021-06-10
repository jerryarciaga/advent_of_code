#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    
    if(input == NULL) {
        printf("%s\n", "File not found.");
        return 1;
    }
    else{
        

    }

    return 0;
}
