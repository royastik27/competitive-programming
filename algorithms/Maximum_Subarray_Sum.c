/**
* Maximum Subarray Sum
* Time Complexity: O(n log n)
* AUTHOR: Astik Roy
* DATE: 24-04-2022
**/

#include <iostream>
#include <climits>

using namespace std;

int middlePortionSum(int ara[], int low, int mid, int high)
{
    int lsum, rsum, i, sum;

    lsum = rsum = INT_MIN;

    // left side
    sum = 0;
    for(i = mid; i >= low; --i)
    {
        sum += ara[i];

        if(sum > lsum) lsum = sum;
    }

    // right side
    sum = 0;
    for(i = mid+1; i <= high; ++i)
    {
        sum += ara[i];

        if(sum > rsum) rsum = sum;
    }

    return (lsum + rsum);
}

int maximumSubarraySum(int ara[], int low, int high)
{
    if(low == high) return ara[low];

    int mid = (low + high) / 2;

    int leftSum = maximumSubarraySum(ara, low, mid);
    int rightSum = maximumSubarraySum(ara, mid+1, high);
    // middle portion sum
    int middleSum = middlePortionSum(ara, low, mid, high);

    return max(max(leftSum, rightSum), middleSum);
}

int main()
{
    int ara[] = { -5, 8, 9, -6, 10, -15, 3 };

    cout << maximumSubarraySum(ara, 0, 6) << '\n';

    return 0;
}
