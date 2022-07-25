#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    vector <int> vec = { 2, 3, 4 };

    vector <int> vec2 = { 5, 6, 7 };

    vec = vec2;

    for(auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    return 0;
}