/**
* Codeforces Round #713 (Div. 3)
* Problem A - Spy Detected!
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include<iostream>
 
using namespace std;
 
int main()
{
    int TC, len, first, curr, position, count;
    register int i;
 
    cin >> TC;
 
    while(TC--)
    {
        cin >> len >> first;
 
        count = 0;
        for(i = 1; i < len; ++i)
        {
            cin >> curr;
 
            if(curr != first)
            {
                position = i + 1;
                ++count;
            }
        }
 
        if(count == len - 1)
            cout << 1 << '\n';
        else
            cout << position << '\n';
    }
 
    return 0;
}
