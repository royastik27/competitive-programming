/**
* UVa 10405 - Longest Common Subsequence
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

#define LIMIT 1001

char str1[LIMIT], str2[LIMIT];
int len1, len2, mem[LIMIT-1][LIMIT-1];

int LCS(int i = 0, int j = 0)
{
    if(i == len1 || j == len2)
        return 0;
    else if(mem[i][j] != -1)
        return mem[i][j];

    if(str1[i] == str2[j])
        mem[i][j] = 1 + LCS(i+1, j+1);
    else
        mem[i][j] = max(LCS(i+1, j), LCS(i, j+1));

    return mem[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while(cin.getline(str1, LIMIT))
    {
        cin.getline(str2, LIMIT);

        len1 = strlen(str1);
        len2 = strlen(str2);

        memset(mem, -1, sizeof(mem));

        cout << LCS() << '\n';
    }

    return 0;
}
