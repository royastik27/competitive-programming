#include <stdio.h>

int main()
{
    int x, y;

    printf("Enter x and y: ");
    scanf("%d %d", &x, &y);

    printf("x / y:\n");
    if(y == 0)
    {
        printf("Quotient: Inf\n");
        printf("Remainder: Undefined\n");
    }
    else
    {
        printf("Quotient: %d\n", x/y);
        printf("Remainder: %d\n", x%y);
    }

    printf("y / x:\n");
    if(x == 0)
    {
        printf("Quotient: Inf\n");
        printf("Remainder: Undefined\n");
    }
    else
    {
        printf("Quotient: %d\n", y/x);
        printf("Remainder: %d\n", y%x);
    }    

    return 0;
}