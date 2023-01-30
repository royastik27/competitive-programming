/**
 * Codeforces Round #585 (Div. 2)
 * Problem B - The Number of Products
 * TIME: 78 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;

#define LIM 200000

class Solution
{

public:
    void solve()
    {
        int n, a[LIM], even, odd, cnt, i;
        bool isEven;
        ll pos, neg;

        cin >> n;

        for(i = 0; i < n; ++i)
            cin >> a[i];

        // for negative
        even = odd = neg = cnt = 0;
        isEven = true;

        for(i = 0; i < n; ++i)
        {
            if(a[i] > 0)
            {
                ++cnt;
                neg += isEven ? even : odd;
            }
            else
            {
                isEven ^= 1;
                
                if(isEven)
                    neg += even += cnt+1;
                else neg += odd += cnt+1;

                cnt = 0;
            }
        }

        // for positive
        even = pos = 0;
        odd = -1;
        isEven = true;

        for(i = 0; i < n; ++i)
        {
            isEven ^= (a[i] < 0);

            if(isEven) pos += ++even;
            else pos += ++odd;
        }

        cout << neg << ' ' << pos << '\n';       

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