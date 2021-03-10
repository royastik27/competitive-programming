/**
* AtCoder Beginner Contest 149
* Problem C - Next Prime
* Time: 7 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    int sqroot = sqrt(num);

    if(num == 2)
        return 2;
    else if(num % 2 == 0)
        return false;

    for(int i = 3; i < sqroot; i+=2)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}

int findGreaterPrime(int num)
{
    int i = num;

    while(1)
    {
        if(isPrime(i))
            return i;

        ++i;
    }

    return -1;
}

int main()
{
    int num;

    cin >> num;

    cout << findGreaterPrime(num) << '\n';

    return 0;
}
