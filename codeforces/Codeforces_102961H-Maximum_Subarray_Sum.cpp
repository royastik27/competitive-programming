/**
* CSES Problem Set: Sorting and Searching
* Problem H - Maximum Subarray Sum
* Time: 358 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <climits>

using namespace std;

#define LIM 200000

int ara[LIM];

long long int maxSubarraySum(int b, int e)
{
    if(b == e) return ara[b];

    int mid = (b + e) / 2;
    long long int leftSum = maxSubarraySum(b, mid);
    long long int rightSum = maxSubarraySum(mid+1, e);

    long long int lsum, rsum, sum;

    lsum = rsum = INT_MIN;

    sum = 0;
    for(int i = mid; i >= b; --i)
    {
        sum += ara[i];
        if(sum > lsum) lsum = sum;
    }

    sum = 0;
    for(int i = mid+1; i <= e; ++i)
    {
        sum += ara[i];
        if(sum > rsum) rsum = sum;
    }

    return max(max(leftSum, rightSum), lsum+rsum);
}

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> ara[i];

    cout << maxSubarraySum(0, n-1) << '\n';

    return 0;
}
