/**
* Codeforces Round 473 (Div. 2)
* Problem C - Mahmoud and Ehab and the wrong algorithm
* TIME: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{

public:
    void solve()
    {
        int n, i;

        cin >> n;

        // for incorrect
        if(n < 6)
            cout << "-1\n";
        else {
            cout << "1 2\n";
            cout << "1 3\n";
            cout << "1 4\n";

            for(i = 5; i <= n; ++i)
                cout << "2 " << i << '\n';
        }

        // for correct
        for(i = 2; i <= n; ++i)
            cout << "1 " << i << '\n';

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    
    sol.solve();

    return 0;
}