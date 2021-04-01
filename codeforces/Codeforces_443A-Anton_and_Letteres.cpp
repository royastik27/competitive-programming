/**
* Codeforces Round #253 (Div. 2)
* Problem A - Anton and Letters
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char wordSet[1001];
    int i, Map[26], len, position, res = 0;

    for(i = 0; i < 26; ++i)
        Map[i] = 0;

    cin.getline(wordSet, 1000);

    len = strlen(wordSet);

    for(i = 1; i < len - 1; i += 3)
    {
        position = wordSet[i] - 'a';
        if(!Map[position])
            ++res;

        ++Map[position];
    }

    cout << res << '\n';

    return 0;
}
