/**
* Codeforces Round #642 (Div. 3)
* Problem C - Board Moves
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n;
    long long int i, sum;

    cin >> TC;

    while(TC--) {
        cin >> n;

        n /= 2;
        sum = 0;

        for(i = 1; i <= n; ++i)
            sum += i*i*8;

        cout << sum << '\n';
    }

    return 0;
}
