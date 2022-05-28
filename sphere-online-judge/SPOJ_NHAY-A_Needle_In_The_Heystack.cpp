/**
 * SPOJ NHAY - A Needle in the Haystack
 * Time: 0.46 sec
 * AUTHOR: Astik Roy
 **/

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define DBG printf("Line %d: FLAG\n", __LINE__);

vector<int> computeLPS(char *str, int len)
{
    vector<int> lps(len);

    int i = 1, j = 0;

    lps[0] = 0;
    while (i < len)
    {
        if (str[i] == str[j])
        {
            lps[i] = j + 1;
            ++i;
            ++j;
        }
        else
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

void print(vector<int> lps)
{
    for (auto it = lps.begin(); it != lps.end(); ++it)
        printf("%d ", *it);
    printf("\n");
}

int main()
{
    int len, i, j, ans;
    vector<int> lps;
    char ch;

    while (scanf("%d", &len) != EOF)
    {
        char *pattern = (char *)malloc(len + 1);
        scanf("%s", pattern);

        lps = computeLPS(pattern, len);

        scanf("%*c");

        // KMP
        j = ans = 0;
        for (i = 1;; ++i)
        {
            scanf("%c", &ch);
            if (ch == '\n')
                break;

            if (ch == pattern[j])
                ++j;
            else // for mismatch
            {
                while (j != 0)
                {
                    if (ch == pattern[j])
                        break;
                    else
                        j = lps[j - 1];
                }

                if (ch == pattern[j])
                    ++j;
            }

            if (j == len)
                printf("%d\n", i - len);
        }

        printf("\n");
    }

    return 0;
}
