/**
* Educational Codeforces Round 146 (Rated for Div. 2)
* Problem C - Search in Parallel
* TIME: 108 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    vector <pii> freq;
    vector <int> first, second;
public:
    void solve()
    {
        int n, s1, s2, i, num, mul_1, mul_2, sz;

        cin >> n >> s1 >> s2;

        for(i = 1; i <= n; ++i)
        {
            cin >> num;

            freq.push_back({ num, i });
        }

        sort(freq.begin(), freq.end(), greater <pii>());

        mul_1 = mul_2 = 1;
        for(i = 0; i < n; ++i)
        {
            if(mul_1*s1 < mul_2*s2)
            {
                first.push_back(freq[i].second);
                ++mul_1;
            }
            else
            {
                second.push_back(freq[i].second);
                ++mul_2;
            }
        }
        
        // printing answer
        sz = first.size();
        cout << sz << ' ';
        for(i = 0; i < sz; ++i) cout << first[i] << ' ';
        cout << '\n';

        sz = second.size();
        cout << sz << ' ';
        for(i = 0; i < sz; ++i) cout << second[i] << ' ';
        cout << '\n';

        // clearing containers
        freq.clear();
        first.clear();
        second.clear();

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