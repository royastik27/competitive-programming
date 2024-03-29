/**
* Educational Codeforces Round 154 (Rated for Div. 2)
* Problem C - Queries for the Array
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

class Solution
{
    int n;
    string str;
    vector <char> mem;
public:
    void solve()
    {
        int i, j, idx;
        char ch;
        bool ans;

        cin >> str;
        n = str.length();

        mem.resize(n+3);

        mem[0] = 's';
        idx = 0;
        ans = true;

        for(i = 0; i < n; ++i) {
            ch = str[i];

            if(ch == '+') {
                if(mem[idx] == 'u')
                    mem[++idx] = 'u';
                else
                    mem[++idx] = 'a';
            }
            else if(ch == '-') {
                --idx;
            }
            else if(ch == '1') {
                if(mem[idx] == 's')
                    continue;
                else if(mem[idx] == 'u') {
                    ans = false;
                    break;
                }
                else {
                    for(j = idx; j > 0 && mem[j] == 'a'; --j)
                        mem[j] = 's';
                }
            }
            else {
                if(mem[idx] == 'u')
                    continue;
                else if(mem[idx] == 's' || idx < 2) {
                    ans = false;
                    break;
                }
                else {
                    mem[idx] = 'u';
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");

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