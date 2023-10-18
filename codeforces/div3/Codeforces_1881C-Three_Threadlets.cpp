/**
* Codeforces Round 903 (Div. 3)
* Problem B - Three Threadlets
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    int a[3];
public:
    void solve()
    {
        bool ans = false;

        cin >> a[0] >> a[1] >> a[2];

        sort(a, a+3);

        if(a[0] == a[1] && a[1] == a[2]) // all equal
            ans = true;
        // operation on only one
        else if(a[0] == a[1] && (a[2] == a[0]*2 || a[2] == a[0]*3LL || a[2] == a[0]*4LL))
            ans = true;
        // operation on two
        else if((a[1] == a[0]*2 && a[2] == a[0]*3LL) || (a[1] == a[0]*2 && a[2] == a[0]*2))
            ans = true;

        if(ans) cout << "YES\n";
        else cout << "NO\n";

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