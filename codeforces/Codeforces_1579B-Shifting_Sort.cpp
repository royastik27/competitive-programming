 /**
  * Codeforces Round #744 (Div. 3)
  * Problem B - Shifting Sort
  * Time: 31 ms
  * AUTHOR: Astik Roy
 **/

 #include <iostream>
 #include <vector>

 using namespace std;

 #define LIM 50
 #define INF 1000000001

 int main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(NULL);

     int TC, n, ara[LIM], mn, mn_pos, offset, sz;
     vector <pair <int, int> > res;
     vector <int> tmp;
     register int i, j, k;

     cin >> TC;

     while(TC--) {
        cin >> n;

        for(i = 0; i < n; ++i) cin >> ara[i];

        for(i = 0; i < n; ++i) {

            mn = INF;
            for(j = i; j < n; ++j)
                if(ara[j] < mn) mn = ara[j], mn_pos = j;

            if(mn_pos == i) continue;

            // getting left values
            for(j = i; j < mn_pos; ++j) tmp.push_back(ara[j]);
            // shifting right values
            for(k = i; j < n; ++k, ++j) ara[k] = ara[j];
            // shifting left values
            for(j = 0; k < n; ++k, ++j) ara[k] = tmp[j];
            tmp.clear();

            offset = mn_pos - i;
            res.push_back(make_pair(i+1, offset));
        }

        sz = res.size();
        cout << sz << '\n';
        for(i = 0; i < sz; ++i)
            cout << res[i].first << ' ' << n << ' ' << res[i].second << '\n';

        res.clear();
     }

     return 0;
 }
