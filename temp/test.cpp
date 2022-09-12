/**
 * Codeforces Round #817 (Div. 4)
 * Problem A - Spell Check
 * TIME: 0 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef long long int ll;

#define MOD 998244353
#define CLUB_LIM 1000

class Solution {
    map < pair <int, int>, int> mp;
    map < pair <int, int>, int>::iterator it, prev;

    int par[CLUB_LIM];

    int Find(int x)
    {
        if(par[x] < 0) return x;

        return Find(par[x]);
    }

    void Union(int x, int y)
    {
        int parX = Find(x), parY = Find(y);

        if(parX == parY) return;

        if(par[parX] < par[parY]) // x is more weighted
        {
            par[parX] += par[parY];
            par[parY] = parX;
        }
        else
        {
            par[parY] += par[parX];
            par[parX] = parY;
        }

        return;
    }

    int Power(int base, int p)
    {
        if(p == 0) return 1;

        if(p & 1)
            return (ll) base * Power(base, p-1) % MOD;

        base = (ll) base * base % MOD;

        return Power(base, p / 2);
    }
public:
    int solve()
    {
        int nClubs, nStudents, nShirts, i, x, left, right;
        ll sum = 0;

        cin >> nClubs >> nStudents >> nShirts;

        for(i = 0; i < nClubs; ++i)
        {
            cin >> x;

            while(x--)
            {
                cin >> left >> right;
                mp[{left, right}] = i;
                sum += right - left + 1;
            }
        }

        // PROCESSING
        memset(par, -1, nClubs * sizeof(int));

        while(mp.size() > 1)
        {
            // INITIALIZATION
            prev = it = mp.begin();
            ++it;

            if(it->first.first <= prev->first.second)
            {
                Union(prev->second, it->second);

                if(it->first.second <= prev->first.second)
                {
                    sum -= it->first.second - it->first.first + 1;
                    mp.erase(it);
                }
                else
                {
                    sum -= prev->first.second - it->first.first + 1;
                    mp.insert({ {prev->first.first, it->first.second}, prev->second });
                    mp.erase(prev);
                    mp.erase(it);
                }
            }
            else mp.erase(prev);
        }

        int cnt = 0;
        for(i = 0; i < nClubs; ++i)
            if(par[i] < 0) ++cnt;

        mp.clear();

        return Power(nShirts, cnt + nStudents - sum);
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
        cout << sol.solve() << '\n';
    
    return 0;
}