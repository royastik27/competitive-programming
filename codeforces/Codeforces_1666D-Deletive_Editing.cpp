/**
* 2021-2022 ICPC, NERC, Northern Eurasia Onsite (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
* Problem D - Deletive Editing
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

typedef long long int ll;

class Solution1
{
    string A, B;
    vector <int> pos[26];
    int need[26];
 
    int idx(char ch) { return int(ch - 'A'); }
public:
    void solve()
    {
        int sz, i, id, nd, to_ins, mx_pos;
        bool possible;
 
        cin >> A >> B;
 
        // getting frequency of A
        sz = A.length();
        for(i = 0; i < sz; ++i)
            pos[idx(A[i])].push_back(i);
 
        // getting needs for B
        memset(need, 0, sizeof(need));
 
        sz = B.length();
        for(i = 0; i < sz; ++i)
            ++need[idx(B[i])];
 
        possible = true;
        // 1st check
        for(i = 0; i < 26; ++i)
            if(need[i] > pos[i].size())
            {
                possible = false;
                break;
            }
        
        // 2nd check
        if(possible)
        {
            mx_pos = -1;
 
            for(i = 0; i < sz; ++i)
            {
                id = idx(B[i]);
 
                nd = need[id];
 
                to_ins = pos[id][pos[id].size() - nd];
 
                if(to_ins < mx_pos)
                {
                    possible = false;
                    break;
                }
 
                --need[id];
 
                mx_pos = max(mx_pos, to_ins);
            }
        }
 
        cout << (possible ? "YES\n" : "NO\n");
 
        for(i = 0; i < 26; ++i)
            pos[i].clear();
 
        return;
    }
};

class Solution2
{
    string A, B;
    stack <int> pos[26];

    int idx(char ch) { return int(ch - 'A'); }
public:
    void solve()
    {
        int sz, i, id, mn_pos;
        bool possible;

        cin >> A >> B;

        // getting frequency of A
        sz = A.length();
        for(i = 0; i < sz; ++i)
            pos[idx(A[i])].push(i);

        // checking
        possible = true;
        sz = B.length();

        mn_pos = A.length();
        for(i = sz - 1; i >= 0; --i)
        {
            id = idx(B[i]);

            if(!pos[id].size() || pos[id].top() > mn_pos) {
                possible = false;
                break;
            }

            mn_pos = min(mn_pos, pos[id].top());
            pos[id].pop();
        }

        cout << (possible ? "YES\n" : "NO\n");

        for(i = 0; i < 26; ++i)
        {
            while(pos[i].size())
                pos[i].pop();
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution2 sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}