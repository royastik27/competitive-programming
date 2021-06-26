/**
* Codeforces Round #288 (Div. 2)
* Problem B - Anton and Currency You All know
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    char num[100001];
    int len, last_dig, pos, dig;
    register int i;

    cin >> num;

    len = strlen(num);

    last_dig = num[len-1];

    pos = -1;
    for(i = 0; i < len - 1; ++i) {
        dig = (int)num[i];

        // if dig is odd
        if(dig & 1) continue;

        pos = i;

        if(dig < last_dig)
            break;
    }

    if(pos == -1) cout << "-1\n";
    else {
        swap(num[pos], num[len-1]);
        cout << num << '\n';
    }

    return 0;
}
