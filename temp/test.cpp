#include <stdio.h>

int main()
{
    char name[20] = "Sohan";

    int i = 0;

    while(name[i] != '\0')
    {
        printf("%d ", (int)name[i]);
        i++;
    }

    printf("\n");

    return 0;
}