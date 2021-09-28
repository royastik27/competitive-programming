/**
 * Codeforces Round #693 (Div. 3)
 * Problem D - Even-Odd Game
 * Time: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, n, el;
    long long alice, bob;
    register int i;
    priority_queue <int> even, odd;

    cin >> TC;

    while(TC--) {
        cin >> n;

        for(i = 0; i < n; ++i) {
            cin >> el;
            if(el & 1) odd.push(el);
            else even.push(el);
        }

        alice = bob = 0;
        bool isAlice = true;

        for(i = 0; i < n; ++i) {
            if(isAlice) {
                if(even.empty()) odd.pop();
                else if(odd.empty()) alice += even.top(), even.pop();
                else {
                    if(odd.top() > even.top()) odd.pop();
                    else alice += even.top(), even.pop();
                }
                isAlice = false;
            }
            else {
                if(even.empty()) bob += odd.top(), odd.pop();
                else if(odd.empty()) even.pop();
                else {
                    if(even.top() > odd.top()) even.pop();
                    else bob += odd.top(), odd.pop();
                }
                isAlice = true;
            }
        }

        if(alice == bob) cout << "Tie\n";
        else if(alice > bob) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}
