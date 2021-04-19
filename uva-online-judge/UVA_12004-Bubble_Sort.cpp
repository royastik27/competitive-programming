/**
* UVA 12004 - Bubble Sort
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main ()
{
    int TC, k = 0, n;
    long long int NOS;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        NOS = (long long int)n*(n-1) / 2;

        cout << "Case " << ++k << ": ";
        if(NOS % 2 == 0)
            cout << NOS/2 << '\n';
        else cout << NOS << '/' << 2 << '\n';
    }

    return 0;
}
