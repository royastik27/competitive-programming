/**
 * https://codeforces.com/contest/279/problem/B
 * Problem 
 * Time: 
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LIM 100000

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, total, pre[LIM], el, res;
    vector <int> time;
    vector <int>::iterator it;
    register int i;

    cin >> n >> total;

    cin >> el;
    time.push_back(el);
    pre[0] = time[0];

    for(i = 1; i < n; ++i) {
        cin >> el;
        time.push_back(el);
        pre[i] = pre[i-1] + time[i];
    }

    res = 0;
    for(it = time.begin(); it != time.end(); ++it) {
        res = max((int)distance(it, upper_bound(time.begin(), time.end(), pre[i]+total)), res);
    }

    cout << res << '\n';

    return 0;
}
