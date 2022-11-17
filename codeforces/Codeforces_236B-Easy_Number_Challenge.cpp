/**
 * Codeforces Round #146 (Div. 2)
 * Problem B - Easy Number Challenge
 * TIME: 124 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

#define LIM 1000000
#define ROOTLIM 1000
#define MOD 1073741824

class Solution{
    vector <int> prime;
    int divisor[LIM + 1];

    void seive()
    {
        int i, j, root;
        bool comp[ROOTLIM + 1] = {};

        prime.push_back(2);
        root = sqrt(ROOTLIM);

        for(i = 3; i <= root; i += 2)
        {
            if(!comp[i])
            {
                for(j = 3*i; j <= ROOTLIM; j += i + i)
                    comp[j] = true;
            }
        }

        for(i = 3; i <= ROOTLIM; i += 2)
            if(!comp[i]) prime.push_back(i);

        return;
    }

    void generate_divisor()
    {
        int i, j, num, root, res = 1, cnt;

        for(i = 1; i <= LIM; ++i)
        {
            num = i;
            root = sqrt(num);
            res = 1;

            for(j = 0; num > 1 && prime[j] <= root; ++j)
            {
                cnt = 1;

                while(num % prime[j] == 0)
                {
                    num /= prime[j];
                    ++cnt;
                }

                res *= cnt;
            }

            if(num > 1) res *= 2;

            divisor[i] = res;
        }

        return;
    }
public:
    Solution()
    {
        seive();
        generate_divisor();        

        return;
    }
    int solve()
    {
        int a, b, c, i, j, k, sum = 0;

        cin >> a >> b >> c;

        for(i = 1; i <= a; ++i)
            for(j = 1; j <= b; ++j)
                for(k = 1; k <= c; ++k)
                    sum = (sum + divisor[i*j*k]) % MOD;
        
        return sum;
    }
};

class Solution2
{
    int divisor[LIM + 1];
public:
    Solution2()
    {
        memset(divisor, 0, sizeof(divisor));

        int i, j;

        for(i = 1; i <= ROOTLIM; ++i)
        {
            ++divisor[i*i];

            for(j = i*i + i; j <= LIM; j += i)
                divisor[j] += 2;
        }

        return;
    }
    int solve()
    {
        int a, b, c, i, j, k, sum = 0;

        cin >> a >> b >> c;

        for(i = 1; i <= a; ++i)
            for(j = 1; j <= b; ++j)
                for(k = 1; k <= c; ++k)
                    sum = (sum + divisor[i*j*k]) % MOD;

        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution2 sol;

    cout << sol.solve() << '\n';

    return 0;
}