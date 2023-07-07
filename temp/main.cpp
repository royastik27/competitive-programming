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
        int n, m, h, i, j, num, time, point;

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
            time = point = 0;

            for(j = 0; j < m; ++j)
            {
                while(time < h)
                {
                    time += inp[i][j];
                    ++point;
                }
            }

            vec.push_back({point, time});

            if(i == 0)
                rud = {point, time};
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
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}