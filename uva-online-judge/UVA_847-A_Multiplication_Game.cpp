/**
* UVA 847 - A Multiplication Game
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

bool play(long long int num, bool position = 0)
{
    num = (position) ? ceil(num / 2.0) : ceil(num / 9.0);

    if(num == 1)
        return position ^ 1;

    return play(num, position ^ 1);
}

int main()
{
    long long int num;

    while(cin >> num)
    {
        if(play(num))   // position = winning : 1, loosing: 0
            cout << "Stan wins.\n";
        else
            cout << "Ollie wins.\n";
    }

    return 0;
}
