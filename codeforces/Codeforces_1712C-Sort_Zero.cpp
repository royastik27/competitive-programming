/**
 * Codeforces Round #813 (Div. 2)
 * Problem C - Sort Zero
 * TIME: 77 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <set>

using namespace std;

#define LIM 100000

class Solution {

public:
    int solve()
    {
        int ans = 0;

        int n, i, arr[LIM];

        cin >> n;
        for(i = 0; i < n; ++i) cin >> arr[i];

        set <int> zero, curr;
        set <int>::iterator it;

        curr.insert(arr[0]);

        for(i = 1; i < n; ++i)
        {
            if(zero.find(arr[i]) != zero.end())
            {
                arr[i] = 0;
                --i;
            }
            else
            {
                if(arr[i] < arr[i-1])
                {
                    ans += curr.size();

                    for(it = curr.begin(); it != curr.end(); ++it)
                        zero.insert(*it);

                    curr.clear();
                    arr[i - 1] = 0;

                    --i;
                }
                else if(arr[i]) curr.insert(arr[i]);
            }
        }

        return ans;
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
        cout << sol.solve() << '\n';
    
    return 0;
}