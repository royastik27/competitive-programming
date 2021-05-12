/**
* UVa 11995 - I Can Guess the Data Structure!
* AUTHOR: Astik Roy
**/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, op, x, output, st, que, prio_que;
    stack <int> s;
    queue <int> q;
    priority_queue <int> pq;

    while(cin >> n)
    {
        output = st = que = prio_que = 0;

        while(n--) {
            cin >> op >> x;

            if(op == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            } else {
                ++output;

                if(s.size() && x == s.top()) {
                    ++st;
                    s.pop();
                }
                if(q.size() && x == q.front()) {
                    ++que;
                    q.pop();
                }
                if(pq.size() && x == pq.top()) {
                    ++prio_que;
                    pq.pop();
                }
            }
        }

        if((st == output && st == que) || (st == output && st == prio_que) || (que == output && que == prio_que))
            cout << "not sure\n";
        else if(output == st)
            cout << "stack\n";
        else if(output == que)
            cout << "queue\n";
        else if(output == prio_que)
            cout << "priority queue\n";
        else
            cout << "impossible\n";

        // resetting
        s = stack <int>();
        q = queue <int>();
        pq = priority_queue <int>();
    }

    return 0;
}
