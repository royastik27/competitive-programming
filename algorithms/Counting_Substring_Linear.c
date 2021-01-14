/**
* Counting Substring - Linear Scan
* AUTHOR: Eng. Astik Roy
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mainLen, subLen, count, i, len;

    printf("Main String Length: ");
    scanf("%d", &mainLen);
    printf("Sub String Length: ");
    scanf("%d", &subLen);

    char * mainStr = (char *)malloc(mainLen*sizeof(char));
    char * subStr = (char *)malloc(subLen*sizeof(char));

    getchar();
    printf("Main String: ");
    gets(mainStr);
    printf("Sub String: ");
    gets(subStr);

    count = len = 0;
    for(i = 0; mainStr[i] != '\0'; ++i)
    {

        if(mainStr[i] != subStr[len])
            len = 0;

        if(mainStr[i] == subStr[len])
            ++len;

        if(subStr[len] == '\0')
        {
            len = 0;
            ++count;
        }
    }

    printf("Number of substring: %d\n", count);

    free(mainStr);
    free(subStr);

    return 0;
}
