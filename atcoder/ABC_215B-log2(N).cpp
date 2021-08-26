/**
 * AtCoder Beginner Contest 215
 * Problem B - log2(N)
 * Time: 5 ms
 * AUTHOR: Astik Roy
**/
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    unsigned long long int num, i;
    int cnt;
    
    cin >> num;
 
    i = 1;
    cnt = -1;

    while(i <= num) {
        ++cnt;
        i *= 2;
    }

    cout << cnt << '\n';
 
    return 0;
}
