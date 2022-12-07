/**
 * Codeforces Round #574 (Div. 2)
 * Problem C - Basketball Exercise
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{

public:
    ll solve()
    {
        int n, i, num;
        vector <int> a, b;
        ll prevA, prevB, currA, currB;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            a.push_back(num);
        }

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            b.push_back(num);
        }
        
        prevA = prevB = 0;

        for(i = 0; i < n; ++i)
        {
            currA = max(prevA, prevB+a[i]);
            currB = max(prevB, prevA+b[i]);

            prevA = currA;
            prevB = currB;
        }

        return max(currA, currB);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';    

    return 0;
}