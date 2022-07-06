/**
 * Codeforces Round #613 (Div. 2)
 * Problem B - Just Eat It!
 * Time: 46 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

long long int max(long long int a, long long int b, long long int c)
{
    return max(max(a, b), c);
}

class Solution
{
    vector <int> vec;

    long long int find_max_sum(int b, int e)
    {
        if(b == e) return vec[b];

        int mid = (b+e) / 2, i;

        long long int lsum = 0, rsum = 0, sum = 0;

        for(i = mid; i >= b; --i)
        {
            sum += vec[i];
            if(sum > lsum) lsum = sum;
        }

        sum = 0;
        for(i = mid + 1; i <= e; ++i)
        {
            sum += vec[i];
            if(sum > rsum) rsum = sum;
        }

        return max(lsum+rsum, find_max_sum(b, mid), find_max_sum(mid+1, e));
    }

    public:
    bool solve()
    {
        int n, el, i;

        cin >> n;

        // INPUT
        long long int totalSum = 0;
        for(i = 0; i < n; ++i)
        {
            cin >> el;
            vec.push_back(el);
            totalSum += el;
        }

        // RESULT OF TWO SIDES
        int mid = (n-1) / 2;
        long long int MaxPartialSum = max(find_max_sum(0, mid), find_max_sum(mid+1, n-1));

        // SUM OF MIDDLE PORTION
        long long int sum = 0, lsum = 0, rsum = 0;
        for(i = mid; i >= 0; --i)
        {
            sum += vec[i];
            if(sum > lsum) lsum = sum;
        }

        sum = 0;
        for(i = mid+1; i < n; ++i)
        {
            sum += vec[i];
            if(sum > rsum) rsum = sum;
        }

        sum = lsum + rsum;

        if(sum == totalSum) sum = max(sum - vec[0], sum - vec[n-1]);

        // ULTIMATE RESEULT
        MaxPartialSum = max(MaxPartialSum, sum);

        // CLEARING VECTOR
        vec.clear();

        // RETURN
        if(totalSum > MaxPartialSum)
            return true;
        
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    int TC;

    cin >> TC;

    while(TC--)
    {
        if(sol.solve()) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}