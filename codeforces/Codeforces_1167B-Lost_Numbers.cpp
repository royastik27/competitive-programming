/**
 * Educational Codeforces Round 65 (Rated for Div. 2)
 * Problem B - Lost Numbers
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <map>

using namespace std;

class Solution
{
    int ara[6] = { 4, 8, 15, 16, 23, 42 };
    map <int, pair <int, int> > m;

    public:
    void solvePartial(int ans[], int start, int end)
    {
        map <int, pair <int, int> >::iterator it1, it2;
        int ab, bc, b;

        // INPUTTING
        cout << "? " << start << ' ' << start + 1 << endl;
        cin >> ab;
        cout << "? " << start + 1 << ' ' << end << endl;
        cin >> bc;

        // GETTING VALUES FROM MAP
        it1 = m.find(ab);
        it2 = m.find(bc);

        if(it1->second.first == it2->second.first || it1->second.first == it2->second.second)
            b = it1->second.first;
        else b = it1->second.second;

        ans[start-1] = ab / b;
        ans[start] = b;
        ans[start+1] = bc / b;

        return;
    }
    void solve(int ans[])
    {
        int i, j;

        for(i = 0; i < 5; ++i)
        {
            for(j = i + 1; j < 6; ++j)
                m.insert(make_pair(ara[i] * ara[j], make_pair(ara[i], ara[j])));
        }

        solvePartial(ans, 1, 3);
        solvePartial(ans, 4, 6);

        return;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    Solution solve;
    int ans[6];

    solve.solve(ans);

    cout << "! ";
    for(int i = 0; i < 6; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
    
    return 0;
}