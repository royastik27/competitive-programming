/**
 * Codeforces Round #166 (Div. 2)
 * Problem B - Prime Matrix
 * TIME: 156 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define LIM 100010

class Solution{
    vector <int> prime;
    int arr[500][500];
public:
    Solution()
    {
        bool comp[LIM];
        int i, j, root;

        memset(comp, 0, sizeof(comp));
        prime.push_back(2);

        root = sqrt(LIM);

        for(i = 3; i <= root; i += 2)
            if(!comp[i])
                for(j = i*3; j < LIM; j += i + i)
                    comp[j] = true;

        for(i = 3; i < LIM; i += 2)
            if(!comp[i]) prime.push_back(i);

        return;
    }
    int solve()
    {
        int n, m, i, j, mn, el, sum;

        cin >> n >> m;

        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                cin >> el;
                arr[i][j] = *lower_bound(prime.begin(), prime.end(), el) - el;
            }

        mn = LIM;

        for(i = 0; i < n; ++i)
        {
            sum = 0;
            for(j = 0; j < m; ++j) sum += arr[i][j];

            mn = min(mn, sum);
        }

        for(i = 0; i < m; ++i)
        {
            sum = 0;
            for(j = 0; j < n; ++j) sum += arr[j][i];

            mn = min(mn, sum);
        }

        return mn;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    Solution sol;

    cout << sol.solve() << '\n';

    return 0;
}