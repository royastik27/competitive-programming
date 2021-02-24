/**
* Codeforces Problem 1095
* Codeforces Round #529 (Div. 3)
* Problem A - Repeating Cipher
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char encrypted[56], decrypted[11];
    int length, i, j, a;

    cin >> length >> encrypted;

    for(i = 0, j = 0, a = 0; i < length; i += a)
    {
        decrypted[j++] = encrypted[i];

        ++a;
    }
    decrypted[j] = '\0';

    cout << decrypted << '\n';

    return 0;
}
