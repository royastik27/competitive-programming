/**
* Codeforces Round #294 (Div. 2)
* Problem B - A and B and Compilation Errors
* Time: 202 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int nErrors, error;
    long long int sum1, sum2, sum3;
    register int i;

    cin >> nErrors;

    sum1 = sum2 = sum3;
    for(i = 0; i < nErrors; ++i)
    {
        cin >> error;
        sum1 += error;

    }

    --nErrors;
    for(i = 0; i < nErrors; ++i)
    {
        cin >> error;
        sum2 += error;

    }

    --nErrors;
    for(i = 0; i < nErrors; ++i)
    {
        cin >> error;
        sum3 += error;

    }

    cout << sum1-sum2 << '\n' << sum2-sum3 << '\n';

    return 0;
}
