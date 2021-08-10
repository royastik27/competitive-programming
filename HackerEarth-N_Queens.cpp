/**
 * HackerEarth - N-Queens
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int n;
bool brd[10][10], col[10], mdia[20], sdia[20], isWin;

void printans()
{
    register int i, j;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j)
            cout << brd[i][j] << ' ';
        cout << '\n';
    }

    return;
}

void nqueens(int row = 0)
{
    if(row == n) {
        isWin = true;
        printans();
        return;
    }

    for(int i = 0;i < n && !isWin; ++i) {
        if(col[i] || mdia[row + i] || sdia[row - i + 9])
            continue;

        brd[row][i] = col[i] = mdia[row + i] = sdia[row - i + 9] = true;
        nqueens(row + 1);
        brd[row][i] = col[i] = mdia[row + i] = sdia[row - i + 9] = false;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;

    if(n == 1) cout << 1 << '\n';
    else if(n < 4) cout << "Not possible\n";
    else nqueens();

    return 0;
}
