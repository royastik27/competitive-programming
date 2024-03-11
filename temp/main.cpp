/**
* [name]
* Problem 
* TIME: 
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
    string s;
public:
    void solve()
    {
        string mapie = "mapie";
        string map = "map";
        string pie = "pie";
        int i, j, k;
        vector <int> freq;

        cin >> n >> s;

        int ans = 0;
        int lim = n-3;

        for(i = 0; i <= lim; ++i) {
            // for mapie
            j = i;
            for(k = 0; k < 5; ++k) {
                int cnt = 0;
                while(j < n && s[j] == mapie[k]) {
                    ++j;
                    ++cnt;
                }

                if(cnt == 0)
                    break;
                
                freq.push_back(cnt);
            }

            if(k == 5) {
                // remove mapie
                ans += min(freq[2], min(freq[0], freq[1]) + min(freq[3], freq[4]));
                i = j-1;
                freq.clear();
                continue;
            }


            // for map
            j = i;
            for(k = 0; k < 3; ++k) {
                int cnt = 0;
                while(j < n && s[j] == map[k]) {
                    ++j;
                    ++cnt;
                }

                if(cnt == 0)
                    break;
                
                freq.push_back(cnt);
            }

            if(k == 3) {
                // remove map
                ans += min(freq[0], min(freq[1], freq[2]));
                i = j-1;
                freq.clear();
                continue;
            }

            // for pie
            j = i;
            for(k = 0; k < 3; ++k) {
                int cnt = 0;
                while(j < n && s[j] == pie[k]) {
                    ++j;
                    ++cnt;
                }

                if(cnt == 0)
                    break;
                
                freq.push_back(cnt);
            }

            if(k == 3) {
                // remove pie
                ans += min(freq[0], min(freq[1], freq[2]));
                i = j-1;
                freq.clear();
                continue;
            }
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