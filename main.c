#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* input;
    input = fopen("input.txt", "r");

    struct point {
        float x, y;
    };

    char str[50];
    while (fgets(str, 50, input) != NULL) {
        printf("%s", str);
    }

    fclose(input);
    return 0;
}