/**
* Codeforces Round #352 (Div. 2)
* Problem B - Different is Good
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    char str[100001];
    int n;

    cin >> n >> str;

    if(n > 26)
        cout << "-1\n";
    else {
        int bits, change, idx;

        bits = change = 0;

        for(int i = 0; i < n; ++i) {
            idx = (int)(str[i] - 'a');

            // checking if the idx th bits is on or not
            if(bits & (1 << idx)) ++change;

            // setting idx th bits
            bits |= (1 << idx);
        }
        cout << change << '\n';
    }

    return 0;
}
