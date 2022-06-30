/**
 * CodeChef ARRAYRET - Retrieve the Array
 * Time: 0.02 sec
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC, n, i;
    long long int b[LIM], diff[LIM], sum, sumDiff, add;

    cin >> TC;
    
    while(TC--)
    {
        cin >> n;

        cin >> b[0];

        diff[0] = sumDiff = 0;
        sum = b[0];

        for(i = 1; i < n; ++i)
        {
            cin >> b[i];
            sum += b[i];

            diff[i] = diff[i-1] + b[i] - b[i-1];
            sumDiff += diff[i];
        }

        // cout << "Difference array:\n";
        // for(i = 0; i < n; ++i)
        //     cout << diff[i] << ' ';
        // cout << '\n';

        add = (sum / (n+1) - sumDiff) / n;

        for(i = 0; i < n; ++i)
            cout << diff[i]+add << ' ';
        cout << '\n';
    }

    return 0;
}
