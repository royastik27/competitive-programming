/**
* Codeforces Round #460 (Div. 2)
* Problem B - Perfect Number
* Unique Solution
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 10000

bool isSum10(int n)
{
    int sum = 0;

    while(n)
    {
        sum += n%10;
        n /= 10;
    }

    return (sum == 10) ? true : false;
}

int main()
{
    int k, i, num;

    cin >> k;

    i = 0;
    num = 10;

    while(i < k)
    {
        num += 9;

        if(isSum10(num))
            ++i;
    }

    cout << num << '\n';

    return 0;
}
