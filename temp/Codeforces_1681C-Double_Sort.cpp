/**
 * Educational Codeforces Round 129 (Rated for Div. 2)
 * Problem C - Double Sort
 * URL: https://codeforces.com/problemset/problem/1681/C
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 100

int main()
{
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

  int TC, a[LIM], b[LIM], minA[LIM];

  cin >> TC;

  while(TC--)
  {
    cin >> n;

    for(i = 0; i < n; ++i) cin >> a[i];
    for(i = 0; i < n; ++i) cin >> b[i];

    // CALCULATE MIN VALUE FROM THE RIGHT
    // FOR I = N
    //    SEARCH FOR MINVAL[I] POSITIONS FROM THE RIGHT
    //      IF A[I] AND B[I] IS ALREADY IN MIN STATE, CONTINUE
    //      IF MATCH FOR BOTH A AND B, THEN SWAP (<-- MAKE MOVE)
    //      IF NOT FOUND, IMPOSSIBLE
    
  }

  return 0;
}
