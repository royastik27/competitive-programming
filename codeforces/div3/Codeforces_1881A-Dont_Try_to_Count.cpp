/**
* Codeforces Round 903 (Div. 3)
* Problem A - Don't Try to Count
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define LIM 25

class Solution
{
    int n, m;
    string a, b, str;

    int find_idx()
    {
        int i, j, len = str.length(), till = len-m;

        for(i = 0; i <= till; ++i)
        {
            for(j = 0; j < m; ++j)
                if(str[i+j] != b[j])
                    break;

            if(j == m)
                return i + (j-1); // last index
        }

        return -1;
    }
public:
    void solve()
    {
        cin >> n >> m;

        cin >> a >> b;

        str = "";
        for(int i = 0; i < LIM; ++i)
            str += a;

        int idx = find_idx();

        if(idx == -1) // not possible
        {
            cout << "-1\n";
            return;
        }

        int th = idx / n + 1;

        int ans = 0, copy = 1;

        while(copy < th)
        {
            ++ans;
            copy *= 2;
        }

        cout << ans << '\n';

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