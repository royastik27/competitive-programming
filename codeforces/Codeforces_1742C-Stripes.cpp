/**
 * Codeforces Round #827 (Div. 4)
 * Problem C - Stripes
 * TIME: 31 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
class Solution {
    char arr[8][8];
public:
    char solve()
    {
        int i, j;
 
        for(i = 0; i < 8; ++i)
            for(j = 0; j < 8; ++j)
                cin >> arr[i][j];
                
        int cnt;
 
        for(i = 0; i < 8; ++i)
        {
            cnt = 0;
 
            for(j = 0; j < 8; ++j)
                if(arr[i][j] == 'R') ++cnt;
 
            if(cnt == 8) return 'R';
        }
 
        for(i = 0; i < 8; ++i)
        {
            cnt = 0;
 
            for(j = 0; j < 8; ++j)
                if(arr[j][i] == 'B') ++cnt;
 
            if(cnt == 8) return 'B';
        }
 
        return 'F';
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
        cout << sol.solve() << endl;
    
    return 0;
}