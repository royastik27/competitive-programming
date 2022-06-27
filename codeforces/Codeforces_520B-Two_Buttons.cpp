/**
 * Codeforces Round #295 (Div. 2)
 * Problem B - Two Buttons
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m;

    cin >> n >> m;

    int op = 0;

    while(m != n)
    {
        if(m < n) { op += n - m; break; }

        if(m & 1) ++m;
        else m /= 2;

        ++op;
    }

    cout << op << '\n';
    
    return 0;
}
