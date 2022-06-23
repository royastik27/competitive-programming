/**
* CodeChef DENSE - Dense Bracket Sequence
* Time: 0.01 sec
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 300001

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC, n, i, j, cnt;
    char str[LIM];

    cin >> TC;

    while(TC--)
    {
        cin >> n >> str;

        i = 0; j = n - 1;
        cnt = 0;

        while(i < j)
        {
            if(str[i] == ')')
                ++cnt, ++i;
            else if(str[j] == '(')
                ++cnt, --j;
            else
                ++i, --j;
        }

        if(i == j) ++cnt;

        cout << cnt << '\n';
    }

    return 0;
}
