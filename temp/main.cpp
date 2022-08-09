/**
 * Codeforces Round #257 (Div. 2)
 * Problem B - Jzzhu and Sequences
 * TIME: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 1001
#define ALICE 0
#define BOB 1

class Solution {

    int upper_bound(int arr[], int n, int val)
    {
        int beg = 1, end = n, mid;

        while(beg <= end)
        {
            mid = (beg + end) / 2;

            if(val < arr[mid]) end = mid - 1;
            else beg = mid + 1;
        }

        return beg;
    }
public:
    void solve()
    {
        int n, i, arr[LIM], forw[LIM], back[LIM];
        cin >> n;

        // prefix sum
        forw[0] = 0;
        for(i = 1; i <= n; ++i)
        { cin >> arr[i]; forw[i] = arr[i] + forw[i - 1]; }

        // suffix sum
        back[0] = 0;
        for(int j = 1, i = n; i > 0; --i, ++j)
            back[j] = back[j - 1] + arr[i];

        int alice, bob, aliceIdx, bobIdx, cnt = 1, aliceScr, bobScr, UB;
        bool player = BOB;

        alice = aliceScr = arr[1];
        aliceIdx = 1;

        bob = bobScr = 0;
        bobIdx = 0;

        while(1)
        {
            if(player == ALICE)
            {
                UB = upper_bound(forw, n, forw[aliceIdx] + bobScr);

                cout << "UB = " << UB << '\n';
                cout << "BOBidx: " << bobIdx << '\n';
                if(UB > n - bobIdx) break;

                aliceScr = forw[UB] - forw[aliceIdx];
                alice += aliceScr;
                aliceIdx = UB;
            }
            else // BOB
            {
                UB = upper_bound(back, n, back[bobIdx] + aliceScr);

                // cout << "UB= " << UB << '\n';

                if(UB > n - aliceIdx) break;

                bobScr = back[UB] - back[bobIdx];
                bob += bobScr;
                bobIdx = UB;
            }

            player ^= 1;
            ++cnt;
        }

        cout << cnt << ' ' << alice << ' ' << bob << '\n';
        
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