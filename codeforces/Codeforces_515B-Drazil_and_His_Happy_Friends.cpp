/**
 * Codeforces Round #292 (Div. 2)
 * Problem B - Drazil and His Happy Friends
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

#define LIM 100

class Solution{

public:
    bool solve()
    {
        int n, m, i, j, lcm;
        bitset <LIM> happy_boy, happy_girl;

        // input
        cin >> n >> m;

        cin >> i;
        while(i--)
        {
            cin >> j;
            happy_boy.set(j);
        }

        cin >> i;
        while(i--)
        {
            cin >> j;
            happy_girl.set(j);
        }
        
        // processing
        lcm = n*m / __gcd(n, m);
        lcm *= 2;

        i = j = 0;
        while(lcm--)
        {
            if(happy_boy[i] || happy_girl[j])
                happy_boy[i] = happy_girl[j] = true;

            i = (i+1) % n;
            j = (j+1) % m;
        }

        return happy_boy.count() + happy_girl.count() == n+m;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    if(sol.solve()) cout << "Yes\n";
    else cout<< "No\n";

    return 0;
}