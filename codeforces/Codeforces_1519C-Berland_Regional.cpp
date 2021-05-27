/**
* Educational Codeforces Round 108 (Rated for Div. 2)
* Problem C - Berland Regional
* Time: 358 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define LIM 200001
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  int TC, n, uni_id[LIM], skill, Size;
  long long int sum, total_sum[LIM], ans[LIM];
  vector <int> uni[LIM];
  vector <long long int> prefix_sum[LIM];
  register int i, j;
  
  cin >> TC;
  
  while(TC--)
  {
      cin >> n;
      
      // input and initialization
      for(i = 1; i <= n; ++i) {
        cin >> uni_id[i];
        uni[i].clear();
        prefix_sum[i].clear();
        prefix_sum[i].push_back(0);
      }
      
      memset(total_sum, 0, sizeof(total_sum));
      
      // pushing students to mentioned universities
      for(i = 1; i <= n; ++i) { 
          cin >> skill;
          
          uni[uni_id[i]].push_back(skill);
          total_sum[uni_id[i]] += skill;
      }
      
      // ready the prefix sum
      for(i = 1; i <= n; ++i) {
          sort(uni[i].begin(), uni[i].end());
          
          sum = 0;
          for(j = 0; j < uni[i].size(); ++j) {
             sum += uni[i][j];
             prefix_sum[i].push_back(sum);
          }
      }
      
      // last operation
      memset(ans, 0, sizeof(ans));
      
      for(i = 1; i <= n; ++i) {
          Size = uni[i].size();
          for(j = 1; j <= Size; ++j) {
              ans[j] += total_sum[i] - prefix_sum[i][Size % j];
          }
      }
      
      // printing result
      for(i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
      cout << '\n';
  }
  
  return 0;
}
