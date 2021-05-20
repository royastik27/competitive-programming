/**
* Codeforces Round #702 (Div. 3)
* Problem C - Sum of Cubes
* Time: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 100000

vector <long long int> num;

void generate_num()
{
    long long int i;
    for(i = 1; i <= LIM; ++i)
        num.push_back(i*i*i);

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    generate_num();

    int TC, low, high;
    long long int x, sum;
    bool is_representable;

    cin >> TC;

    while(TC--)
    {
        cin >> x;

        low = 0;
        high = LIM - 1;

        is_representable = false;

        // two pointer method for matching sum of two elements
        while(low <= high)
        {
            sum = num[low] + num[high];

            if(sum == x) {
                is_representable = true;
                break;
            }
            else if(sum > x)
                --high;
            else
                ++low;
        }

        if(is_representable) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
