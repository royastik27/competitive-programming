/**
* Codeforces Round 927 (Div. 3)
* Problem D - Card Game
* TIME: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

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
    char trump;
    vector <string> suit[4];
    vector <char> type;

    int suit_idx(char ch)
    {
        int i, sz = type.size();

        for(i = 0; i < 4; ++i)
            if(ch == type[i])
                return i;

        return -1;
    }
public:
    Solution()
    {
        type = vector <char>{ 'C', 'D', 'H', 'S' };
        return;
    }
    void solve()
    {
        int i, j, trump_idx, idx, tot_cards, cnt_odd, trump_sz, trump_rest, sz;
        string card;

        cin >> n >> trump;

        trump_idx = suit_idx(trump);

        tot_cards = 2*n;
        for(i = 0; i < tot_cards; ++i) {
            cin >> card;

            idx = suit_idx(card[1]);
            suit[idx].push_back(card);
        }

        // checking validity
        cnt_odd = 0;
        for(i = 0; i < 4; ++i) {
            if(i == trump_idx) {
                trump_sz = suit[i].size();
            }
            else if(suit[i].size() & 1) {
                ++cnt_odd;
            }
        }

        trump_rest = trump_sz - cnt_odd;

        if(trump_rest < 0 || trump_rest & 1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            // generating answer
            for(i = 0; i < 4; ++i)
                sort(suit[i].begin(), suit[i].end());

            // with trump if odd
            for(i = 0; i < 4; ++i) {
                if(i == trump_idx)
                    continue;

                if(suit[i].size() & 1) {
                    cout << suit[i][suit[i].size()-1] << ' ' << suit[trump_idx][suit[trump_idx].size()-1] << '\n';
                    suit[i].pop_back();
                    suit[trump_idx].pop_back();
                }
            }

            for(i = 0; i < 4; ++i) {
                sz = suit[i].size();
                for(j = 1; j < sz; j += 2) {
                    cout << suit[i][j-1] << ' ' << suit[i][j] << '\n';
                }
            }
        }

        // clearing container
        for(i = 0; i < 4; ++i)
            suit[i].clear();

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