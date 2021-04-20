/**
* Codeforces Round #503 (by SIS, Div. 2)
* Problem B - Badge
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <bitset>

#define LIMIT 1001

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int nStudents, reported[LIMIT], ans[LIMIT], i, curr;
    bitset <LIMIT> bits;

    cin >> nStudents;

    for(i = 1; i <= nStudents; ++i)
        cin >> reported[i];

    for(i = 1; i <= nStudents; ++i)
    {
        bits.reset();

        curr = i;
        while(!bits[curr])
        {
            bits.set(curr);
            curr = reported[curr];
        }

        ans[i] = curr;
    }

    for(i = 1; i <= nStudents; ++i)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
