#include <stdio.h>

int main()
{
    FILE* fp;
    char name[] = "input.txt";
    if ((fp = fopen(name, "r")) == NULL) {
        printf("Error: Can't open input.txt file");
        getchar();
    } else {
        printf("File was opened successfully");
    }

    fclose(fp);
    getchar();

    return 0;
}
