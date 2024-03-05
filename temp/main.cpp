/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <set>

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
    vector <int> a;
    set <int> s;
public:
    void solve()
    {
        int n, i;

        cin >> n;

        s.resize(n);

        for(i = 0; i < n; ++i) {
            cin >> a[i];
            s.insert(a[i]);
        }
        
        int total_mex = 0;
        for(it = s.begin(), i = 0; it != s.end(); ++it, ++i) {
            if(*it != i) {
                total_mex = i;
                break;
            }
        }

        // 2nd phase
        s.clear();
        ans.push_back(1);

        for(i = 0; i < n; ++i) {
            if(a[i] < total_mex) {
                s.insert(a[i]);
            }

            if(s.size() == total_mex) {
                ans.push_back(i+1);
                ans.push_back(i+2);
                s.clear();
            }
        }

        if(ans.size() == 3) 
            cout << "-1\n";
        else {
            ans.pop_back();
            ans.pop_back();
            ans.push_back(n);

            int sz = ans.size();
            cout << (sz / 2) << '\n';
            
            for(i = 1; i < n; i += 2) {
                cout << a[i-1] << ' ' << a[i] << '\n';
            }
        }


        s.clear();

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