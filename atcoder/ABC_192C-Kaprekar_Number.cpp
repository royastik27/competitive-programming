/**
* AtCoder Beginner Contest 192
* Problem C - Kaprekar Number
* Time: 34 ms
* Author: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char * myFunction(char num[])
{
    char asc[11], desc[11], resStr[11];
    int len, res, i;

    len = strlen(num);

    // getting ascending and descending ordered number
    sort(num, num + len);
    strcpy(asc, num);

    sort(num, num+len, greater<int>());
    strcpy(desc, num);

    // omitting leading zeros and subtracting
    res = atoi(desc) - atoi(asc);

    // corner case for the condition used in while lopp
    if(!res){
        num[0] = '0';
        num[1] = '\0';
        return num;
    }

    // casting integer result to string
    i = 0;
    while(res)
    {
        num[i++] = (res % 10) + '0';

        res /= 10;
    }
    reverse(num, num + i);
    num[i] = '\0';

    return num;
}

int main()
{
    char num[11];
    int k;

    cin >> num >> k;

    for(int i = 0; i < k; ++i)
        strcpy(num, myFunction(num));

    cout << num << '\n';

    return 0;
}
