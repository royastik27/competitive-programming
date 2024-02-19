/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

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
    int n;

    bool check(int x, int y)
    {
        int x2, y2;

        x2 = x;
        while(x2+1 <= n && a[x2+1][y] == '1')
            ++x2;

        if(x == x2) 
            return false;

        y2 = y + x2 - x;

        for(i = x; i <= x2; ++i) {
            for(j = y; j <= y2; ++j) {
                if(a[i][j] != '1')
                    return false;
            }
        }

        return true;
    }

    bool isSquare(int n)
    {
        int i, j;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                if(a[i][j] == '1')
                    return check(i, j);
            }
        }

        return false;
    }
public:
    void solve()
    {
        cin >> n;

        for(i = 0; i < n; ++i) {
            for(j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }

        if(isSquare()) cout << "SQUARE\n";
        else cout << "TRIANGLE\n";

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}