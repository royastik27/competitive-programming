/**
* Codeforces Round 905 (Div. 3)
* Problem D - In Love
* TIME: 155 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

typedef long long int ll;

class Solution
{
    multiset <int> left, right;
    multiset <int>::iterator leftMx, rightMn;
public:
    void solve()
    {
        int n, l, r;
        char op;

        cin >> n;

        while(n--)
        {
            cin >> op >> l >> r;

            if(op == '+') {
                left.insert(l);
                right.insert(r);
            }
            else
            {
                left.erase(left.find(l));
                right.erase(right.find(r));
            }

            if(!left.size())
                cout << "NO\n";
            else {
                leftMx = --left.end();
                rightMn = right.begin();

                if(*leftMx > *rightMn)
                    cout << "YES\n";
                else cout << "NO\n";
            }
        }

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    sol.solve();

    return 0;
}