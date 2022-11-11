/**
 * Codeforces Round #410 (Div. 2)
 * Problem B - Mike and strings
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 50

class Solution {

    int op(string str1, string str2)
    {
        int i, j, sz = str1.size();

        if(sz != str2.size()) return -1;

        for(i = 0; i < sz; ++i)
        {
            for(j = 0; j < sz; ++j)
                if(str1[(i+j) % sz] != str2[j])
                    break;

            if(j == sz)
                return i;
        }       

        return -1;
    }

public:
    int solve()
    {
        int n, i, j, ans = LIM*LIM, re, temp;
        vector <string> vec;
        string str;

        cin >> n;

        for(i = 0; i < n; ++i)
        {
            cin >> str;
            vec.push_back(str);
        }

        for(i = 0; i < n; ++i)
        {
            temp = 0;

            for(j = 0; j < n; ++j)
            {
                re = op(vec[j], vec[i]);

                if(re == -1) return -1;

                temp += re;
            }

            ans = min(ans, temp);
        }

        return ans;
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
