/**
* Codeforces Round 903 (Div. 3)
* Problem D - Divide and Equalize
* TIME: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef long long int ll;

#define LIM 1000000
#define PRIME_LIM 1010

class Solution
{
    map <int, int> mp;
    map <int, int>::iterator it;
    vector <int> prime;

public:
    Solution()
    {
        prime.push_back(2);

        int i, j;
        bool comp[PRIME_LIM+1];

        memset(comp, 0, sizeof(comp));

        for(i = 3; i*i <= PRIME_LIM; i += 2)
        {
            for(j = i*i; j <= PRIME_LIM; j += i + i)
                comp[j] = true;
        }

        for(i = 3; i <= PRIME_LIM; i += 2)
            if(!comp[i])
                prime.push_back(i);

        return;
    }

    void solve()
    {
        int n, i, j, num, cnt;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> num;

            for(j = 0; prime[j]*prime[j] <= num; ++j)
            {
                if(num % prime[j] == 0)
                {
                    cnt = 0;

                    while(num % prime[j] == 0)
                        { num /= prime[j], ++cnt; }
                    
                    if(cnt)
                        mp[prime[j]] += cnt;
                }
            }

            if(num > 1)
                ++mp[num];
        }

        for(it = mp.begin(); it != mp.end(); ++it)
            if(it->second % n != 0)
                break;

        if(it == mp.end()) cout << "YES\n";
        else cout << "NO\n";

        mp.clear();

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