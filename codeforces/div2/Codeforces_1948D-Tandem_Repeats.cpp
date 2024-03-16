/**
* Educational Codeforces Round 163 (Rated for Div. 2)
* Problem D - Tandem Repeats?
* TIME: 156 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

#define LIM 5020

class Solution
{
    int n;
    string str;
    bool mem[LIM][LIM];

    bool possible(int x)
    {
        int i, cnt;

        cnt = 0;

        for(i = 0; i < x; ++i)
            if(mem[i][x])
                ++cnt;

        if(cnt == x)
            return true;

        for(; i < n; ++i) {
            cnt -= mem[i-x][x];
            cnt += mem[i][x];

            if(cnt == x)
                return true;
        }

        return false;
    }
public:
    void solve()
    {
        int i, j;

        cin >> str;

        n = str.length();

        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                mem[i][j] = false;

        for(i = 0; i < n; ++i) {
            for(j = 1; i-j >= 0; ++j) {
                if(str[i] == '?' || str[i-j] == '?' || str[i-j] == str[i])
                    mem[i][j] = true;
            }
        }

        int mx_len = 0;
        int half_len = n/2;

        for(i = 1; i <= half_len; ++i)
            if(possible(i))
                mx_len = i;

        mx_len *= 2;

        cout << mx_len << '\n';

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