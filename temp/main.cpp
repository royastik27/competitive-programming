/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define LIM 200010

bool cmp(pii a, pii b)
{
    if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    else
    {
        if(a.second < b.second)
            return true;
        else
            return false;        
    }    
}

class Solution
{
    pii rud;
    vector <int> inp[LIM];
    vector <pii> vec;

    bool compare(pii x)
    {
        if(rud.first > x.first)
            return true;
        else if(rud.first < x.first)
            return false;
        else
        {
            if(rud.second > x.second)
                return false;
            else
                return true;
        }        
    }
public:
    void solve()
    {
        int n, m, h, i, j, num, time, point, penalty;

        cin >> n >> m >> h;

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                cin >> num;
                inp[i].push_back(num);
            }

            sort(inp[i].begin(), inp[i].end());
        }

        for(i = 0; i < n; ++i)
        {
            time = penalty = point = 0;

            j = 0;
            while(j < m)
            {
                if(time + inp[i][j] > h)
                    break;

                time += inp[i][j];
                penalty += time;

                ++point;
                ++j;
            }

            vec.push_back({point, penalty});

            if(i == 0)
                rud = {point, penalty};
        }

        sort(vec.begin(), vec.end(), cmp);

        int pos = 1;

        for(i = 0; i < n; ++i)
        {
            if(compare(vec[i]))
                break;
            
            ++pos;
        }

        cout << pos << '\n';

        for(i = 0; i < n; ++i)
            inp[i].clear();

        vec.clear();

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