/**
* Codeforces Round #710 (Div. 3)
* Problem B - Partial Replacement
* Totally Unique Solution
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, star[50], j, len, k, op, last;
    char str[51];
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> len >> k >> str;

        for(i = 0, j = 0; str[i] != '\0'; ++i)
        {
            if(str[i] == '*')
                star[j++] = i;
        }

        op = 0;
        for(i = star[0]; i <= star[j-1]; i += k)
        {
            i = *(upper_bound(star, star+j, i) - 1);
            last = i;
            ++op;
        }

        if(last != star[j-1])
            ++op;

        cout << op << '\n';
    }

    return 0;
}
