#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec(100);

    for(int i = 0; i < 100; ++i)
        cout << vec[i] << ' ';
    cout << '\n';


    return 0;
}