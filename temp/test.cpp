#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ara[] = { 10, 20, 30, 40, 50 };
    int n = sizeof(ara) / sizeof(ara[0]);

    cout << *upper_bound(ara, ara+n, 20) << '\n';

    return 0;
}