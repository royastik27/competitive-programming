/**
* AtCoder Beginner Contest 203
* Problem B - AtCoder Condominium
* Time: 4 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
int main()
{
    int n, k, i, j, sum = 0;
 
    cin >> n >> k;
 
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= k; ++j) {
            sum += i * 100 + j;
        }
    }
 
    cout << sum << '\n';
 
    return 0;
}
