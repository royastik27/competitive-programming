/**
* Codeforces Round #636 (Div. 3)
* Problem C - Alternating Subsequence
* Time: 140 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int TC, n, Max, el;
    long long int sum;
    bool isPositive;    // what we need
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        cin >> el;

        // verifying first element
        sum = Max = el;
        isPositive = (el > 0) ? false : true;

        for(i = 1; i < n; ++i)
        {
            cin >> el;

            if((isPositive && el > 0) || (!isPositive && el < 0))
            {
                sum += el;
                isPositive ^= 1;
                Max = el;
            }
            else if(el > Max)
            {
                sum = sum - Max + el;
                Max = el;
            }
        }

        cout << sum << '\n';
    }

    return 0;
}
