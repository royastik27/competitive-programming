/**
 * Interactive Problem Training Contest
 * Problem 1 - Guess the Number
 * Time: 15 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIM 1000000

int main()
{
    ios_base::sync_with_stdio(false);
    
    int start = 1, end = LIM, mid, ans;
    char inp[3];

    while(start <= end)
    {
        mid = (start + end) / 2;

        // endl flushes autotically
        cout << mid << endl;

        cin >> inp;
        
        if(inp[0] == '<')
            end = mid - 1;
        else
            { ans = mid; start = mid + 1; }
    }

    // no need to use endl here
    cout << "! " << ans << '\n';

    return 0;
}
