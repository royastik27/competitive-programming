/**
 * https://codeforces.com/contest/1512/problem/D
 * Problem
 * Time:
 * AUTHOR: Astik Roy
 * Implement using map
**/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    multiset <long long int> s;
    multiset <long long int>::iterator curr, it, bn;

    int TC, n, el;
    long long int sum, temp;
    bool flag;

    cin >> TC;

    while(TC--) {
        cin >> n;

        sum = 0;
        n+=2;
        while(n--) {
            cin >> el;
            sum += el;
            s.insert(el);
        }

        flag = false;
        for(curr = s.begin(); curr != s.end(); ++curr) {
            temp = sum - *curr;

            if(temp & 1) continue;

            temp /= 2;
            bn = s.find(temp);
            if(bn == s.end()) continue;
            else if(bn == curr) continue;

            flag = true;
            break;
        }

        if(flag) {
            for(it = s.begin(); it != s.end(); ++it) {
                if(it == curr || it == bn) continue;
                cout << *it << ' ';
            }
            cout << '\n';
        } else cout << "-1\n";

        s.clear();
    }

    return 0;
}
