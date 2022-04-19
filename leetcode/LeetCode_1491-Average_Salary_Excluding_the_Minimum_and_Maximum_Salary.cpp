class Solution {
public:
    double average(vector<int>& salary) {
        int mn, mx, sz = salary.size(), sum;

        mn = mx = sum = salary[0];
        for(int i = 1; i < sz; ++i)
        {
            if(salary[i] < mn) mn = salary[i];
            else if(salary[i] > mx) mx = salary[i];

            sum += salary[i];
        }

        return (double)(sum - mn - mx) / (sz - 2);
    }
};
