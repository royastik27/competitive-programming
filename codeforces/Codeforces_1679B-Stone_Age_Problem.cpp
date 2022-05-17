/**
 * Codeforces Round #791 (Div. 2)
 * Problem B - Stone Age Problem
 * Time: 327 ms
 * AUTHOR: Astik Roy
 **/

#include <iostream>
#include <cstring>

using namespace std;

#define LIM 200000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, nQuries, a[LIM], lastSingleUpdate[LIM];
    long long int sum = 0;

    // INPUTTING
    cin >> n >> nQuries;
    memset(lastSingleUpdate, -1, n * sizeof(int));

    int i;
    for (i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    // QUERIES
    int op, idx, lastAllUpdate = -2, allUpVal, newVal;

    for (i = 0; i < nQuries; ++i)
    {
        cin >> op;

        switch (op)
        {
        case 1:
            cin >> idx >> newVal;
            --idx; // for 0-based indexing

            if (lastSingleUpdate[idx] < lastAllUpdate)
                // for first time update after resetting
                sum -= allUpVal;
            else
                // for updated at least once
                sum -= a[idx];

            lastSingleUpdate[idx] = i; // updating index
            a[idx] = newVal;           // updating value

            sum += newVal;
            break;
        case 2:
            cin >> newVal;
            lastAllUpdate = i;               // updating index
            allUpVal = newVal;               // updating value
            sum = (long long int)newVal * n; // updating sum
            break;
        }

        cout << sum << '\n';
    }

    return 0;
}
