#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> vec;

    auto it = lower_bound(vec.begin(), vec.end(), 5);

    if(it == vec.end())
        cout << "LAST\n";
    else
    cout << (it - vec.begin()) << '\n';    

    return 0;
}