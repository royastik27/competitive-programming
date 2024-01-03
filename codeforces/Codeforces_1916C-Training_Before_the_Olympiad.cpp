/**
* Good Bye 2023
* Problem C - Training Before the Olympiad
* TIME: 78 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    void solve()
    {
        int n, i, num, odd;
        ll sum;

        cin >> n >> num;

        cout << num << ' ';

        sum = num;
        odd = num & 1;

        for(i = 1; i < n; ++i) {
            cin >> num;

            if(num & 1) ++odd;

            sum += num;

            cout << (sum - odd/3 - (odd % 3 == 1)) << ' ';
        }

        cout << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}