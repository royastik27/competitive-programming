/**
* [name]
* Problem 
* TIME: 
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

typedef long long int ll;
typedef pair <int, int> pii;

#define ALICE 0
#define BOB 1
#define DRAW 2

class Solution
{
    int pos_winner;

    int play(int palyer = ALICE, int x1, int y1, int x2, int y2)
    {
        if(y1 == y2)
            return pos_winner;
        
        if(x1 == x2)
            return DRAW;

        if(player == ALICE) {
            if(pos_winner == ALICE)
        }
    }
public:
    void solve()
    {
        cin >> h >> w >> x1 >> y1 >> x2 >> y2;

        if(x1 >= x2)
            ans = DRAW;
        else {
            if((x2 - x1) & 1)
                pos_winner = ALICE;
            else
                pos_winner = BOB;
            
            ans = play(x1, y1, x2, y2);
        }

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