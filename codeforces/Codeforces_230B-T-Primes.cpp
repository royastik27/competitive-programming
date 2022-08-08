/**
 * Codeforces Round #142 (Div. 2)
 * Problem B - T-primes
 * TIME: 310 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    
    bool isPrime(int x)
    {
        if(x == 2) return true;
        else if(!(x & 1)) return false;
        else
        {
            int root = sqrt(x);
            for(int i = 3; i <= root; i += 2)
            {
                if(x % i == 0)
                    return false;
            }
        }

        return true;
    }
    
public:
    bool solve()
    {
        long long int num;
        cin >> num;

        if(num == 4) return true;
        else
        {
            double root = sqrt((double)num);

            if(root == 1) return false;

            if(root == (int)root && isPrime(root)) return true;

            return false;
        }
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
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    
    return 0;
}