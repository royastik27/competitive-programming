/**
* Codeforces Beta Round 2
* Problem A - Winner
* TIME: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

typedef long long int ll;

class Solution
{
    vector < pair<string, int> > v;
    vector <string> wins;
    map <string, int> mp, mp2;
    map <string, int>::iterator it;
    pair < map<string,int>::iterator, bool > check;

    bool find_wins(string str)
    {
        int i, sz = wins.size();
        
        for(i = 0; i < sz; ++i)
            if(wins[i] == str)
                return true;

        return false;
    }
public:
    void solve()
    {
        int n, i, score, mx;
        string name, ans;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> name >> score;
            
            v.push_back({ name, score });
            mp[name] += score;
        }

        mx = 0; // at the end, at least one player has a positive number of points

        for(it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->second > mx)
            {
                ans = it->first;
                mx = it->second;
                wins.clear();
                wins.push_back(it->first);
            }
            else if(it->second == mx)
                wins.push_back(it->first);
        }

        if(wins.size() > 1)
        {
            for(i = 0; i < n; ++i)
            {
                check = mp2.insert({ v[i].first, v[i].second });

                it = check.first; // extracting the iterator

                if(!check.second)   // if already has
                    it->second += v[i].second;

                if(it->second >= mx && find_wins(it->first)) {
                    ans = it->first;
                    break;
                }
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
    
    sol.solve();

    return 0;
}