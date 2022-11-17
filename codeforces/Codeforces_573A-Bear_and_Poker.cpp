/**
 * Codeforces Round #318 [RussianCodeCup Thanks-Round] (Div. 1)
 * Problem A - Bear and Poker
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

class Solution{

public:
    bool solve()
    {
        int n, el, prev;

        cin >> n >> el;

        while(el % 6 == 0)
            el /= 6;
        while(el % 3 == 0)
            el /= 3;
        while(el % 2 == 0)
            el /= 2;

        prev = el;

        --n;
        while(n--)
        {
            cin >> el;

            while(el % 6 == 0)
                el /= 6;
            while(el % 3 == 0)
                el /= 3;
            while(el % 2 == 0)
                el /= 2;

            if(el != prev) return false;
        }
        
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    if(sol.solve()) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}