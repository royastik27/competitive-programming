/**
* Codeforces Round #470 (rated, Div. 2, based on VK Cup 2018 Round 1)
* Problem A - Protect Sheep
* Time: 108 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 500

char posture[LIMIT][LIMIT];

int row, col;

bool set_dog(int i, int j)
{
    if(i < 0 || i == row || j < 0 || j == col || posture[i][j] == 'W')
        return true;
    else if(posture[i][j] == 'S')
        return false;

    posture[i][j] = 'D';

    return true;
}

bool set_all_dog(int i, int j)
{
    return !(!set_dog(i+1, j) || !set_dog(i-1, j) || !set_dog(i, j+1) || !set_dog(i, j-1));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int i, j;

    cin >> row >> col;

    for(i = 0; i < row; ++i)
        for(j = 0; j < col; ++j)
            cin >> posture[i][j];

    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
        {
            if(posture[i][j] == 'W')
            {
                if(set_all_dog(i, j) == false)
                {
                    cout << "No\n";
                    return 0;
                }
            }
        }
    }

    cout << "Yes\n";
    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
            cout << posture[i][j];
        cout << '\n';
    }

    return 0;
}
