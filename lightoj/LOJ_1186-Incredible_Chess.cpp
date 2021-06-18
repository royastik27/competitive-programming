/**
* LightOJ 1186 - Incredible Chess
* Nim Game Concept
* Time: 9 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, k = 0, dim, white[100], black, sum;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> dim;

        for(i = 0; i < dim; ++i)
            cin >> white[i];

        sum = 0;
        for(i = 0; i < dim; ++i)
        {
            cin >> black;

            sum ^= black - white[i] - 1;
        }

        cout << "Case " << ++k << ": ";

        if(sum) cout << "white wins\n";
        else cout << "black wins\n";
    }

    return 0;
}
