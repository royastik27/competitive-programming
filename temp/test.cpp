#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> vec(0);
    vector <int>::iterator it;

    int i, n, el, mx = 0;

    cin >> n;
    for(i = 0; i < n; ++i)
    {
        cin >> el;
        vec.push_back(el);

        if(el > mx)
        {
            mx = el;
            it = max_element(vec.begin(), vec.end());
        }

        cout << "vec.size(): " << vec.size() << '\n';

        cout << "max element: " << *it << '\n';
    }

    // cout << "max element: " << *it << '\n';


    return 0;
}