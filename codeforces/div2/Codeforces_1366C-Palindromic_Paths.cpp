/**
 * Educational Codeforces Round 89 (Rated for Div. 2)
 * Problem C - Palindromic Paths
 * TIME: 61 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define LIM 31

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, row, col, ans, lim, half, freq[2], i, j;
    bool m[LIM][LIM];
    vector < set < pair <int, int> > > vec;
    set < pair <int, int> >::iterator it, it2;
    vector < pair <int, int> > temp;
    
    cin >> TC;

    while (TC--)
    {
        cin >> row >> col;
        
        for(i = 1; i <= row; ++i)
            for(j = 1; j <= col; ++j)
                cin >> m[i][j];

        vec.push_back(set <pair <int, int> >({ {1, 1} }));
        
        lim = row + col - 2;    // -1 for the next loop

        for(i = 0; i < lim; ++i)
        {
            for(it = vec[i].begin(); it != vec[i].end(); ++it)
            {
                // go right
                if(it->second != col)
                    temp.push_back({ it->first, it->second+1 });

                // go down
                if(it->first != row)
                    temp.push_back({ it->first+1, it->second });
            }

            vec.push_back(set < pair <int, int> >(temp.begin(), temp.end()));
            temp.clear();
        }
        // vec.size() = lim + 1

        half = (lim+1) / 2;
        ans = 0;

        for(i = 0; i < half; ++i)
        {
            freq[0] = freq[1] = 0;
            
            for(it = vec[i].begin(); it != vec[i].end(); ++it)
                ++freq[m[it->first][it->second]];

            for(it2 = vec[lim-i].begin(); it2 != vec[lim-i].end(); ++it2)              
                ++freq[m[it2->first][it2->second]];

            if(freq[0] && freq[1])
                ans += min(freq[0], freq[1]);
        }

        cout << ans << '\n';

        vec.clear();
    }

    return 0;
}