/**
* Codeforces Round 420 (Div. 2)
* Problem C - Okabe and Boxes
* TIME: 140 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <stack>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    int reorder, desired;
    stack <int> st;

    void remove(int r)
    {
        while(st.size() && r) {
            if(st.top() == desired) {
                ++desired;
                st.pop();
                --r;
            }
            else {
                ++reorder;
                
                while(st.size())
                 st.pop();
            }
        }
        
        while(r) {
        	++desired;
        	--r;
        }
    }
public:
    void solve()
    {
        int n, nOP, i, num, r;
        string op;

        cin >> n;

        nOP = 2*n;
        reorder = r = 0;
        desired = 1;

        for(i = 0; i < nOP; ++i) {
            cin >> op;

            if(op.compare("add") == 0) {
                
                if(r) {
                    remove(r);
                    r = 0;
                }

                cin >> num;
                st.push(num);
            }
            else ++r;
        }

        remove(r);

        cout << reorder << '\n';

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