#include <iostream>
#include <vector>

using namespace std;

void CHANGE(vector <int> vec)
{
    vec[0] = 10;
    vec[1] = 0;

    return;
}

int main()
{
    vector <int> vec = { 1, 2, 3, 4 };

    CHANGE(vec);

    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n';

    return 0;
}