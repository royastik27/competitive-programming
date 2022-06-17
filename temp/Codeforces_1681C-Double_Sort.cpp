/**
 * Educational Codeforces Round 129 (Rated for Div. 2)
 * Problem C - Double Sort
 * URL: https://codeforces.com/problemset/problem/1681/C
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define LIM 101

bool checkBit(int n, int pos)
{
    return n & (1 << pos);
}

void setBit(int * n, int pos) { *n |= (1 << pos); }

void printPosition(int ara[], int n)
{
    int i, j;

    cout << "positions:\n";
    for(i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for(j = 1; j <= n; ++j)
        {
            if(checkBit(ara[i], j)) cout << j << ' ';
        }
        cout << '\n';
    }
}

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
    // cin.tie(NULL);

    int a[LIM], sortedA[LIM], b[LIM], sortedB[LIM], TC, n, i, j, posA[LIM], posB[LIM];
    bool impossible;
    vector <pair <int, int> > swaps;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        memset(posA, 0, (n+1)*sizeof(int));
        memset(posB, 0, (n+1)*sizeof(int));

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sortedA[i] = a[i];
            setBit(&posA[a[i]], i);
        }

        for(i = 1; i <= n; ++i)
        {
            cin >> b[i];
            sortedB[i] = b[i];
            setBit(&posB[b[i]], i);
        }

        // SORTING
        sort(sortedA, sortedA+n+1);
        sort(sortedB, sortedAB+n+1);

        // MAIN OPERATION
        impossible = false;

        for(i = 1; i <= n - 1; ++i)
        {
            if(a[i] == sortedA[i])
            {
                if(b[i] == sortedB[i])
                    continue;
                else
                {
                    // check other positions of a[i] that match with any position of sortedB[i]
                    for(j = i + 1; j <= n; ++j)
                    {
                        if(checkBit(posA[a[i]], j) && checkBit(posB[sortedB[i]], j))
                        {
                            // update positions
                            // swapping
                            swap(&a[i], &a[j]);
                            swap(&b[i], &b[j]);
                            // updating answers
                            swaps.push_back(i, j);
                            break;
                        }
                    }

                    if(j > n)
                    {
                        // not found
                        impossible = true;
                        break;
                    }
                }
            }
            else
            {
                for(j = i + 1; j <= n; ++j)
                {
                    if(checkBit(posA[a[i]], j) && checkBit(posB[sortedB[i]], j))
                    {
                        // update positions
                        // swapping
                        swap(&a[i], &a[j]);
                        swap(&b[i], &b[j]);
                        // updating answers
                        swaps.push_back(i, j);
                        break;
                    }
                }
                // if b is sorted
                // if not sorted
            }
        }

        if(impossible) cout << -1 << '\n';
        else
        {
            cout << swaps.size() << '\n';
            for(i = 0; i < swaps.size(); ++i)
                cout << swaps[i].first << ' ' << swaps[i].second << '\n';
            swaps.clear();
        }
    }

    return 0;
}

    return 0;
}
