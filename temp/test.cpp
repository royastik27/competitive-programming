#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int> s;
    pair < set <int>::iterator, bool > check;

    s.insert(10);

    check = s.insert(20);

    for(auto it = s.begin(); it != s.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    s.clear();

    cout << "AFTER CLEARING\n";
    for(auto it = s.begin(); it != s.end(); ++it)
        cout << *it << ' ';
    cout << "\n";

    return 0;
}