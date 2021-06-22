/**
* Codeforces Round #620 (Div. 2)
* Problem B - Longest Palindrome
* Time: 30 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bool isPair(string a, string b)
{
    int sz = a.size(), i, j;

    for(i = 0, j = sz-1; i < sz; ++i, --j) {
        if(a[i] != b[j]) return false;
    }

    return true;
}

bool isPalindrome(string a)
{
    int i, j, half_sz;

    j = a.size();
    half_sz = j / 2;
    --j;

    for(i = 0; i < half_sz; ++i, --j) {
        if(a[i] != a[j]) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int n, m, sz = 0;
    string palindrome;
    vector <string> inp, res1, res2;
    bitset <100> bits;
    bool found;
    register int i, j;

    // taking input
    cin >> n >> m;

    for(i = 0; i < n; ++i) {
        cin >> palindrome;  // for temporary use only
        inp.push_back(palindrome);
    }

    // main operation
    palindrome = "";
    for(i = 0; i < n-1; ++i) {  // curr = inp[i]

        // if inp[i] is taken then continue;
        if(bits[i]) continue;
        // else check for pairs
        found = false;
        for(j = i+1; j < n; ++j) {
            if(isPair(inp[i], inp[j])) {
                // push in ans
                res1.push_back(inp[i]);
                res2.push_back(inp[j]);

                // taken inp[j]
                bits.set(j);

                // calc size
                sz += 2*m;
                found = true;
                break;
            }
        }

        // if found then mark as taken
        if(!found && isPalindrome(inp[i])) {
            palindrome = inp[i];
        }
    }

    // checking the last string as palindrome
    if(!bits[n-1] && isPalindrome(inp[n-1]))
        palindrome = inp[n-1];

    if(palindrome != "")
        sz += m;

    // printing the result
    cout << sz << '\n';

    sz = res1.size();
    for(i = 0; i < sz; ++i)
        cout << res1[i];

    if(palindrome != "")
        cout << palindrome;

    for(i = res2.size() - 1; i >= 0; --i)
        cout << res2[i];

    cout << '\n';

    return 0;
}
