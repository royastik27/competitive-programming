/**
* Atcoder Beginner Contest 186
* Problem C - Unlucky 7
* Time: 9 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

bool no7(int number)
{
    while(number)
    {
        if(number%10 == 7)
            return 0;

        number /= 10;
    }

    return 1;
}

int toOctal(int number)
{
    int toMultiply = 1, res = 0;

    while(number)
    {
        res = res + (number%8)*toMultiply;
        toMultiply *= 10;
        number /= 8;
    }

    return res;
}

int main()
{
    int number, res = 0, i;

    cin >> number;

    for(i = 1; i<=number; ++i)
    {
        if(no7(i) && no7(toOctal(i)))
            ++res;
    }

    cout << res << '\n';

    return 0;
}
