/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution
{
    int n;
    vector <int> vec, ans, temp;

    bool compare()
    {
        int i;

        for(i = 0; i < n; ++i)
            if(temp[i] > ans[i])
                return true;

        return false;
    }

    void go(int b, int e)
    {
        int i;

        for(i = e+1; i < n; ++i)
            temp.push_back(vec[i]);

        for(i = e; i >= b; --i)
            temp.push_back(vec[i]);

        for(i = 0 i < b; ++i)
            temp.push_back(vec[i]);

        if(compare())
            for(i = 0; i < n; ++i)
                ans[i] = temp[i];

        temp.clear();

        return;
    }
public:
    void solve()
    {
        int num, i;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> num;
            vec.push_back(num);
            ans.push_back(num);
        }

        go(0, 0);

        for(i = 0; i < n; ++i)
        {
            //
        }

        vec.clear();
        ans.clear();

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