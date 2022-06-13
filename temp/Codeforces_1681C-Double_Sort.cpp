/**
 * Educational Codeforces Round 129 (Rated for Div. 2)
 * Problem C - Double Sort
 * URL: https://codeforces.com/problemset/problem/1681/C
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 100
#define INF 101 // check again

void swap(int ara[], int i, int j)
{
  ara[i] = ara[i] + ara[j];
  ara[j] = ara[i] - ara[j];
  ara[i] = ara[i] - ara[j];

  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int TC, n, a[LIM], b[LIM], minA[LIM], i, j, x;

  cin >> TC;
  
  cout << "HERE\n";

  while(TC--)
  {
    cin >> n;

    for(i = 0; i < n; ++i) cin >> a[i];
    for(i = 0; i < n; ++i) cin >> b[i];

    cout << "HERE\n";

    // CALCULATE MIN VALUE FROM THE RIGHT
    // FOR I = N
    //    SEARCH FOR MINVAL[I] POSITIONS FROM THE RIGHT
    //      IF A[I] AND B[I] IS ALREADY IN MIN STATE, CONTINUE
    //      IF MATCH FOR BOTH A AND B, THEN SWAP (<-- MAKE MOVE)
    //      IF NOT FOUND, IMPOSSIBLE

    vector <int> minPosA, minPosB;
    int minA, minB;

    
    for(i = 0; i < n - 1; ++i)
    {
      minA = minB = INF;

      for(j = n - 1; j >= i; --j)
      {
        if(a[j] == minA) minPosA.push_back(j);
        else if(a[j] < minA) { minA = a[j]; minPosA.clear(); minPosA.push_back(j); }

        if(b[j] == minB) minPosB.push_back(j);
        else if(b[j] < minB) { minB = b[j]; minPosB.clear(); minPosB.push_back(j); }
      }

      cout << "HERE\n";

      if(a[i] == minA && b[i] == minB) continue;
      else
      {
        bool found = false;
        for(int x = 0; x < minPosA.size() && x < minPosB.size(); ++x)
        {
          if(minPosA[x] == minPosB[x]) { found = true; break; }
        }

        if(!found) { cout << "Impossible\n"; break; }

        cout << "Swapping " << i + 1 << " and " << x + 1 << '\n';
        swap(a, i, x);
      }
    }    
  }

  return 0;
}
