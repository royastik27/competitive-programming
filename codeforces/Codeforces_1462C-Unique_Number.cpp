/**
* Codeforces Round #690 (Div. 3)
* Problem C - Unique Number
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int find_min(int i, int need, int num)
{
    if(need == 0) return num;
    else if(need < 0 || i > 9)
        return INT_MAX;

    return min(find_min(i+1, need-i, num*10 + i), find_min(i+1, need, num));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, x, res;

    cin >> TC;

    while(TC--)
    {
        cin >> x;

        res = find_min(1, x, 0);

        if(res == INT_MAX) cout << -1 << '\n';
        else cout << res << '\n';
    }

    return 0;
}
