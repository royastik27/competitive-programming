/**
 * AtCoder Beginner Contest 215
 * Problem C - One More aab aba baa
 * Time: 8 ms
 * AUTHOR: Astik Roy
**/
 
#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    char str[9];
    int k, len;
 
    cin >> str >> k;
 
    len = strlen(str);
 
    while(prev_permutation(str, str+len));
 
    next_permutation(str, str+len);
 
    while(--k) {
        next_permutation(str, str+len);
    }
 
    cout << str << '\n';
 
    return 0;
}
