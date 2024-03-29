/**
* Codeforces Beta Round 67 (Div. 2)
* Problem C - Modified GCD
* TIME: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <functional>

using namespace std;
// using namespace __gnu_pbds;

typedef long long int ll;
typedef pair <int, int> pii;

// typedef tree<int , null_mapped_type ,  less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set;
// typedef tree<int , null_mapped_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

class Solution
{   
    int a, b;
    vector <int> divisor;

    void divisors(int n)
    {
        int i;

        for(i = 1; i*i < n; ++i) {
            if(n % i == 0) {
                divisor.push_back(i);
                divisor.push_back(n/i);
            }
        }

        if(i*i == n)
            divisor.push_back(i);

        sort(divisor.begin(), divisor.end());
    }
public:
    void solve()
    {
        int d, low, high, n, sz, i, ans;

        cin >> a >> b;

        d = __gcd(a, b);

        divisors(d);
        sz = divisor.size();

        cin >> n;
        
        while(n--) {
            cin >> low >> high;

            ans = -1;
            for(i = 0; i < sz; ++i) {
                if(divisor[i] >= low && divisor[i] <= high)
                    ans = divisor[i];
            }

            cout << ans << '\n';
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