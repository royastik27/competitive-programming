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

int days[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Solution
{
    map <int> mp[7];
public:
    void solve()
    {
        int i;
        string inp;

        getline(cin, inp);

        int year = 0;
        for(i = 6; i <= 9; ++i) {
            year = year * 10 + int(dateStr[i]-'0');
        }

        bool leapYear = false;
        if(year % 4 == 0 || (year % 100 == 0 && year % 400 == 0))
            leapYear = true;

        if(leapYear)
            days[2] = 29;
        else days[2] = 28;

        int month = 0;
        month = month * 10 + int(dateStr[3]-'0');
        month = month * 10 + int(dateStr[4]-'0');




        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;
    int TC;

    cin >> TC;

    while(TC--)
        sol.solve();

    return 0;
}