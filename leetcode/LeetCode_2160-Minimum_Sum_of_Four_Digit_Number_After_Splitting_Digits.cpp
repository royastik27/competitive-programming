/**
 * LeetCode 2160 - Minimum Sum of Four Digit Number After Splitting Digits
 * Time: 5 ms
 * AUTHOR: Astik Roy
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumSum(int num)
    {
        int digit[4];

        for (int i = 0; i < 4; ++i)
        {
            digit[i] = num % 10;
            num /= 10;
        }

        sort(digit, digit + 4);

        return digit[0] * 10 + digit[2] + digit[1] * 10 + digit[3];
    }
};

int main()
{
    Solution obj;

    int n;
    while (cin >> n)
        cout << obj.minimumSum(n) << '\n';

    return 0;
}
