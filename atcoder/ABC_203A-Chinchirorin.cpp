/**
* AtCoder Beginner Contest 203
* Problem A - Chinchirorin
* Time: 9 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
int main()
{
    int a, b, c;
 
    cin >> a >> b >> c;
 
    if(a == b)
        cout << c << '\n';
    else if(b == c)
        cout << a << '\n';
    else if(c == a)
        cout << b << '\n';
    else
        cout << 0 << '\n';
 
    return 0;
}
