/**
 * UVA 424 - Integer Inquiry
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int pnt[100], n, sum, mx, i, j, k;
    char num[101][101], res[103] = "0";

    i = 0;
    mx = -1;
    while(cin >> num[i] && num[i][0] != '0') {
        pnt[i] = strlen(num[i]) - 1;
        if(pnt[i] > mx) mx = pnt[i];
        ++i;
    }

    n = i;
    sum = 0;
    k = -1;
    for(i = 0; i <= mx ; ++i) {
        for(j = 0; j < n; ++j) {
            if(pnt[j] == -1) continue;

            sum += (int)(num[j][pnt[j]] - '0');
            --pnt[j];
        }

        res[++k] = (char)(sum % 10 + '0');
        sum /= 10;
    }

    while(sum) {
        res[++k] = (char)(sum % 10 + '0');
        sum /= 10;
    }

    res[++k] = '\0';
    reverse(res, res + k);

    cout << res << '\n';

    return 0;
}
