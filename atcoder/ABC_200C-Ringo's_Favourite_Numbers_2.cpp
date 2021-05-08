/**
* AtCoder Beginner Contest 200
* Problem C - Ringo's Favorite Numbers 2
* Time: 
* AUTHOR: Astik Roy
**/

#include <cstring>
 
using namespace std;
 
int main()
{
    // find same congruence classes
    int n, el, cls[200], i;
    long long res;
 
    memset(cls, 0, sizeof(cls));
 
    cin >> n;
 
    while(n--)
    {
        cin >> el;
        ++cls[el % 200];
    }
 
    res = 0;
    for(i = 0; i < 200; ++i)
    {
        if(cls[i] > 1)
            res += (long long)cls[i] * (cls[i]-1) / 2;
    }
 
    cout << res << '\n';
 
    return 0;
}
