/**
* NEXT PROBLEM :: UVA 10302 - Summation of Polynomials
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char ara[1000], temp[1000];
    int i, j, size;
    bool isPalindrome;

    while(1)
    {
        cin.getline(temp, 1000);

        //base case
        if(strcmp(temp, "DONE")==0)
            break;
        //no input checking
        else if(temp[0] == '\0')
            continue;

        //copying the elements except quotation marks to another array
        j = 0;
        for(i = 0; temp[i]!='\0'; ++i)
        {
            if(temp[i] == ' ' || temp[i] == '.' || temp[i] == ',' || temp[i] == '!' || temp[i] == '?')
                continue;
            else
            {
                if(temp[i] < 91)
                    temp[i]+=32;

                ara[j] = temp[i];
                ++j;
            }
        }

        isPalindrome = 1;

        //if ara[] isn't filled
        if(!j)  goto result;

        //checking palindrome
        size = j-1;
        for(i = 0; i<=size/2; ++i)
        {
            if(ara[i] != ara[size-i])
            {
                isPalindrome = 0;
                break;
            }
        }

        result:
        if(isPalindrome)
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }

    return 0;
}
