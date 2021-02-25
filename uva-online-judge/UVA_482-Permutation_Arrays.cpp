/**
* UVA 482 - Permutation Arrays
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define LIMIT 1000001

int main()
{
    int TC, permute[LIMIT], nElements, i, k = 0;
    char str[LIMIT], * token;
    char number[LIMIT][1000];

    cin >> TC;
    getchar();

    while(TC--)
    {
        getchar();
        cin.getline(str, LIMIT);

        // process permute index
        i = 0;
        token = strtok(str, " ");

        while(token != NULL)
        {
            permute[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
        nElements = i;
        
        cin.getline(str, LIMIT);
        
        // process numbers
        i = 0;
        token = strtok(str, " ");

        while(token != NULL)
        {
            strcpy(number[permute[i++] - 1], token);
            token = strtok(NULL,  " ");
        }

        // each case is separated by a blank line
        if(k++) cout << '\n';

        for(i = 0; i<nElements; ++i)
        {
            cout << number[i] << '\n';
        }
    }

    return 0;
}
