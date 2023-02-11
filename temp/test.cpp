/**
 * Codeforces Round #479 (Div. 3)
 * Problem E - Cyclic Components
 * TIME: 93 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

class Solution
{
    string str;

    int get_num(int n)
    {
        int i, num = 0;

        for(i = 0; i < n; ++i)
        {
            num = num * 10 + int(str[0]-'0');
            str.erase(str.begin());
        }

        return num;
    }

    ll hash_time()
    {
        int day = get_num(2);
        str.erase(str.begin());

        int month = get_num(2);
        str.erase(str.begin());

        int year = get_num(4);
        str.erase(str.begin());

        int hour = get_num(2);
        str.erase(str.begin());

        int min = get_num(2);
        str.erase(str.begin());

        int sec = get_num(2);

        ll ans = 0;

        ans += year * 10000000000LL;
        ans += month * 100000000LL;
        ans += day * 1000000LL;
        ans += hour * 10000LL;
        ans += min * 100LL;
        ans += sec * 1LL;

        return ans;
    }

public:
    void solve()
    {

        cin >> str;

        cout << "str: " << str << '\n';
        

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