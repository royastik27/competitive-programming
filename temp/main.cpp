/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>
#include <list>
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

int days[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string bars[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

class Solution
{
   list <int> mp[7];

    void etoTomo(int er, int tomo)
    {
        if(tomo > mp[er].size()-1) {
                cout << "-";
        }

        auto it = mp[er].begin();
        int i;

        for(i = 0; i < tomo; ++i)
            ++it;

        cout << *it;
    }

   void print_ans()
   {
       int i;

       cout << "|---------------------------|\n";
       cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|\n";
        cout << "|---------------------------|\n";

        for(j = 0; j < 5; ++j) {          

            for(i = 0; i < 7; ++i) {
                // days
                etoTomo(i, j);
            }
        }

    
   }
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

        int day = 0;
        day = day * 10 + int(dateStr[0]-'0');
        day = day * 10 + int(dateStr[1]-'0');

        string bar;
        for(i = 11; i <= 13; ++i)
            bar.push_back(dateStr[i]);

        // bar calculation
        int barIdx = 0;
        for(i = 0; i < 7; ++i) {
            if(bars[i].compare(bar) == 0) {
                barIdx = i;
                break;
            }
        }

        int curr = barIdx;
        int firstbar;

        for(i = day; i <= days[month]; ++i) {

            mp[barIdx].push_back(i);

            if(day == 1)
                firstBar = barIdx;

            barIdx = (barIdx+1) % 7;

        }

        if(barIdx == 0)
            curr = 6;
        else
            curr = barIdx - 1;

        for(i = day-1; i >= 1; --i) {
            mp[barIdx].push_back(i);

            if(day == 1)
                firstbar = barIdx;

            if(barIdx == 0)
                curr = 6;
            else
                curr = barIdx - 1;
        }

        // printing answer
        for(i = 0; i < 7; ++i)
            mp[i].sort();

        // overflow case
        if(barIdx == 5 && days[month] == 31) {
            mp[0].pop_back(31);
            mp[0].push_front(31);
        }
        else
            mp[0].front(0);

        if(barIdx == 6 && days[month] == 30) {
            mp[0].pop_back(30);
            mp[0].push_front(30);
        }
        
        if(barIdx == 6 && days[month] == 31) {
            mp[0].pop_back(30);
            mp[0].push_front(30);

            mp[1].pop_back(31);
            mp[1].push_front(31);
        }
        else
            mp[1].push_front(0);

        // for tue
        if(firstbar >= 3)
            mp[2].push_front(0);
        // for wed
        if(firstbar >= 4)
            mp[3].push_front(0);
        // for thu
        if(firstbar >= 5)
            mp[4].push_front(0);
        // for fri
        if(firstbar >= 6)
            mp[5].push_front(0);

        // ready
        // for(i = 0; i < 7; ++i) {

        // }

        // printing answer
        print_ans();

        for(i = 0; i < 7; ++i)
            mp[i].clear();


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