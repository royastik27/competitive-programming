/**
* Codeforces Round #627 (Div. 3)
* Problem B - Yet Another Palindrome Problem
* Totally Unique Solution in O(n) Time Complexity
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 5000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC, len, occur[LIMIT + 1], prev, el;
    register int i;
    bool isPalindrome;

    cin >> TC;

    while(TC--)
    {
        memset(occur, 0, sizeof(occur));

        cin >> len;

        isPalindrome = false;
        cin >> prev;
        ++occur[prev];

        for(i = 1; i < len; ++i)
        {
            cin >> el;
            ++occur[el];

            // if any number appears more than twice
            if(occur[el] > 2)
                isPalindrome = true;

            // if one number appears twice with another number between two of them
            if(el != prev && occur[el] > 1)
                isPalindrome = true;

            prev = el;
        }

        if(isPalindrome) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
