/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

class Solution
{
    set <int> st;
    set <int>::iterator it;
    vector <int> vec;

    int go(int b, int e)
    {
        int avg = (vec[b] + vec[e]) / 2;

        int ans = 0;
        for(int i = b; i <= e; ++i)
            ans = max(ans, abs(vec[i]-avg));

        return ans;
    }
public:
    void solve()
    {
        int n, i, num;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            st.insert(num);
        }

        for(it = st.begin(); it != st.end(); ++it)
            vec.push_back(*it);

        n = vec.length();

        if(n < 4)
        {
            ans = 0;
        }
        else
        {
            vector <pii> temp;

            for(i = 1; i < n; ++i)
                temp.push_back({ vec[i] - vec[i-1], i });

            sort(temp.begin(), temp.end(), greater <pii>);

            vector <int> pos;
            pos.push_back(temp[0].second);
            pos.push_back(temp[1].second);

            sort(pos.begin(), pos.end());

            ans = 0;
            ans = max(ans, go(0, pos[0]-1));
            ans = max(ans, go(pos[0], pos[1]-1));
            ans = max(ans, go(pos[1], n-1));
        }

        cout << ans << '\n';

        st.clear();
        vec.clear();

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