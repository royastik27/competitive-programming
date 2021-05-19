/**
* Codeforces Round #710 (Div. 3)
* Problem C - Double-ended Strings
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

char a[21], b[21];

int solve2(int i, int j)
{
    if(a[i] == '\0' || b[j] == '\0')
        return 0;
    else if(a[i] == b[j])
        return 1 + solve2(i+1, j+1);

    return 0;
}

int solve1(int i)
{
    int j, LCS = 0;

    for(j = 0; b[j] != '\0'; ++j)
    {
        LCS = max(LCS, solve2(i, j));
    }

    return LCS;
}

int find_LCS()  // longest common sub-string
{
    int i, LCS = 0;
    for(i = 0; a[i] != '\0'; ++i)
    {
        LCS = max(LCS, solve1(i));
    }

    return LCS;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    /** Find the Longest Common Sub-string **/
    int TC, len1, len2, LCS;

    cin >> TC;

    while(TC--)
    {
        cin >> a >> b;

        len1 = strlen(a);
        len2 = strlen(b);

        LCS = find_LCS();

        cout << (len1+len2) - 2*LCS << '\n';
    }

    return 0;
}
