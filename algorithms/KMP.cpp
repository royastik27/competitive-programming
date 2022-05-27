/**
 * Knuth–Morris–Pratt Algorithm
**/

#include <iostream>
#include <vector>

using namespace std;

vector<int> computeLPS(string pattern)
{
    int sz = pattern.length();

    vector<int> lps(sz);

    lps[0] = 0;
    int i = 1, j = 0;

    while (i < sz)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            ++i;
            ++j;
        }
        else // for mismatch
        {
            if (j == 0)
            {
                lps[i] = 0;
                ++i;
            }
            else
                j = lps[j - 1];
        }
    }

    return lps;
}

void KMP(string str, string pattern)
{
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0, sz = pattern.length();

    while (i < str.length())
    {
        if (str[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            if (j == 0)
                ++i;
            else
                j = lps[j - 1];
        }

        if (j == sz)
            cout << "FOUND at " << i - sz << '\n';
    }

    return;
}

int main()
{
    KMP("AstikAstikAstik", "Astik");

    return 0;
}
