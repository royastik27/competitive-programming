/**
* Codeforces Round #710 (Div. 3)
* Problem A - Strange Table
* Time: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int TC, nRows, nCols;
    long long int x, res, row, col;

    cin >> TC;

    while(TC--)
    {
        cin >> nRows >> nCols >> x;

        row = x % nRows;
        if(row == 0) row = nRows;
        col = ceil((double)x / nRows);

        res = nCols * (row - 1) + col;

        cout << res << '\n';
    }

    return 0;
}

