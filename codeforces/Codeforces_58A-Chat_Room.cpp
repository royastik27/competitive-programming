/**
* Codeforces Beta Round #54 (Div. 2)
* Problem A - Chat Room
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    char word[101], hello[6] = "hello";
    register int i, j;

    cin >> word;

    for(i = 0, j = 0; word[i] != '\0'; ++i) {
        if(word[i] == hello[j])
            ++j;
    }

    if(j > 4) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
