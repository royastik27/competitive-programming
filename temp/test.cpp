/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    void tell(int a, int b) {
        cout << "a and b: " << a << ' ' << b << '\n';
    }
public:
    void solve()
    {
        int a = 10;
        tell(a--, a);

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    sol.solve();

    return 0;
}