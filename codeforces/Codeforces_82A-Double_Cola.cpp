/**
* Yandex.Algorithm 2011: Qualification 2
* Problem A - Double Cola
* Totally Unique Solution
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define LIMIT 30

int main()
{
    int n, dist, idx;
    vector <int> vec;
    vector <int>::iterator it;
    char name[5][8] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

    cin >> n;

    vec.push_back(0);
    for(int i = 1; ; ++i)
    {
        vec.push_back(vec[i-1] + pow(2, i-1)*5);

        if(vec[i] >= n)
            break;
    }

    it = lower_bound(vec.begin(), vec.end(), n);
    --it;
    dist = distance(vec.begin(), it);

    idx = ceil((double)(n - *it) / pow(2, dist));

    cout << name[idx-1] << '\n';

    return 0;
}
