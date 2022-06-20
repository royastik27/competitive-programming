/**
* Educational Codeforces Round 129 (Rated for Div. 2)
* Problem C - Double Sort
* Time: 0 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define LIM 101

void swap(int * a, int * b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[LIM], sortedA[LIM], b[LIM], sortedB[LIM], TC, n, i, j;
    bitset <LIM> posA[LIM], posB[LIM];
    bool impossible;
    vector <pair <int, int> > swaps;

    a[0] = b[0] = sortedA[0] = sortedB[0] = 0;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sortedA[i] = a[i];
            posA[a[i]].set(i);
        }

        for(i = 1; i <= n; ++i)
        {
            cin >> b[i];
            sortedB[i] = b[i];
            posB[b[i]].set(i);
        }

        // SORTING
        sort(sortedA, sortedA+n+1);
        sort(sortedB, sortedB+n+1);

        // MAIN OPERATION
        impossible = false;

        for(i = 1; i <= n - 1; ++i)
        {
            if(a[i] == sortedA[i] && b[i] == sortedB[i])
                continue;
            else
            {
                for(j = i + 1; j <= n; ++j)
                {
                    if(posA[sortedA[i]][j] && posB[sortedB[i]][j])
                    {                        
                        // UPDATING POSITIONS
                        // for a
                        posA[a[i]].reset(i);
                        posA[a[j]].reset(j);

                        posA[a[i]].set(j);
                        posA[a[j]].set(i);

                        // for b
                        posB[b[i]].reset(i);
                        posB[b[j]].reset(j);

                        posB[b[i]].set(j);
                        posB[b[j]].set(i);

                        // swapping
                        swap(&a[i], &a[j]);
                        swap(&b[i], &b[j]);

                        // updating answers
                        swaps.push_back(make_pair(i, j));
                        break;
                    }
                }

                if(j > n) // not found
                {
                    impossible = true;
                    break;
                }
            }
        }

        // PRINTING RESULTS
        if(impossible) cout << -1 << '\n';
        else
        {
            cout << swaps.size() << '\n';
            for(i = 0; i < swaps.size(); ++i)
                cout << swaps[i].first << ' ' << swaps[i].second << '\n';
        }

        // RESETTING CONTAINERS
        for(i = 1; i <= n; ++i)
            posA[i].reset(), posB[i].reset();

        swaps.clear();
    }

    return 0;
}
