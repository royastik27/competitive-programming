/**
* UVA 377
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>

int strcop(char found[], char result[])
{
    int i;
    for(i = 7; i>=0; i--)
    {
        if(result[i]!=found[i])
        {
            return 0;
        }
    }
    return 1;
}

void copy(char num2[], char temp[], int ** top2)
{
    int i, j;

    for(i = **top2, j = 0; i>=0; i--, j++)
    {
        num2[j] = temp[i];
    }

    return;
}

char addChar(char a, char b, char * carry)
{
    char Ccarry = 'x', sum;

    if(a == 'V')
    {
        if(b == a)
            sum = a;
        else
            sum = b;
    }
    else if(a == 'U')
    {
        if(b == 'V')
            sum = a;
        else if(b == a)
            sum = 'C';
        else if(b == 'C')
            sum = 'D';
        else
        {
            sum = 'V';
            Ccarry = a;
        }
    }
    else if(a == 'C')
    {
        if(b == 'V')
            sum = a;
        else if(b == 'U')
            sum = 'D';
        else if(b == a)
        {
            sum = 'V';
            Ccarry = 'U';
        }
        else
        {
            sum = Ccarry = 'U';
        }
    }
    else
    {
        if(b == 'V')
            sum = a;
        else if(b == 'U')
        {
            sum = 'V';
            Ccarry = b;
        }
        else if(b == 'C')
            sum = Ccarry = 'U';
        else
        {
            sum = 'C';
            Ccarry = 'U';
        }
    }

    _Bool isCarry = 0;
    if(*carry != 'x')
    {
        char b = 'x';
        sum = addChar(sum, *carry, &b);
        if(b != 'x')
        {
            *carry = b;
            isCarry = 1;
        }
    }

    if(!isCarry)
    {
        *carry = Ccarry;
    }

    return sum;
}

void sum2(char num1[], char num2[], int * top2)
{
    char temp[8], carry = 'x';
    int i, j, k;

    for(i = 4, j = *top2, k = 0; i>=0; i--, j--, k++)
    {
        temp[k] = addChar(num1[i], num2[j], &carry);
    }
    char tempchar = carry;
    char tempCarry = 'x';
    while(tempchar != 'x')
    {
        if(j<0)
        {
            temp[k] = tempchar;
            k++;
            break;
        }
        temp[k] = addChar(num2[j], tempchar, &tempCarry);
        tempchar = tempCarry;
        k++;
        j--;
    }
    for(; j>=0; j--, k++)
    {
        temp[k] = num2[j];
    }
    *top2 = k-1;

    copy(num2, temp, &top2);

    return;
}

void rightShift(char ara[], int *top2)
{
    int i;
    for(i = *top2; i>0; i--)
        ara[i] = ara[i-1];

    ara[0] = 'V';

    return;
}

void leftShift(char ara[], int *top2)
{
    int a = *top2;

    ara[a+1] = 'V';
    ara[a+2] = '\0';
    (*top2)++;

    return;
}

void makeResult(char num2[], char result[], int * top2)
{
    int i = 0, j;
    for(; i<7-(*top2); i++)
    {
        result[i] = 'V';
    }
    for(j = 0; j<=(*top2); j++, i++)
    {
       result[i] = num2[j];
    }
    result[i] = '\0';

    return;
}

int main()
{
    int test, i, j;
    char num1[6], num2[9], result[9], found[9], choice;

    scanf("%d", &test);

    for(i = 0; i<test; i++)
    {
        getchar();
        scanf("%s %s", num1, num2);

        int top2 = 4;

        getchar();

        for(j = 0; j<3; j++)
        {
            scanf("%c", &choice);

            switch(choice)
            {
            case 'A':
                sum2(num1, num2, &top2);
                break;
            case 'R':
                rightShift(num2, &top2);
                break;
            case 'L':
                leftShift(num2, &top2);
                break;
            }
            getchar();
        }

        scanf("%s", found);

        makeResult(num2, result, &top2);

        if(i == 0)
        {
            printf("COWCULATIONS OUTPUT\n");
        }

        if(strcop(found, result))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    printf("END OF OUTPUT\n");

    return 0;
}
