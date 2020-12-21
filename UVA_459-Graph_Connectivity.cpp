/**
* UVA 459 - Graph Connectivity
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int ara[27], count;

int Find(int x)
{
    if(ara[x] < 0)
        return x;

    return Find(ara[x]);
}

void Union(int x, int y, int max)
{
    int parentX = Find(x), parentY = Find(y);

    if(parentX == parentY)
        return;

    if(parentX != x) ara[x] = parentX;
    if(parentY != y) ara[y] = parentY;

    if(ara[parentX] <= ara[parentY])
    {
        ara[parentX] = ara[parentX]+ara[parentY];
        ara[parentY] = parentX;

    }
    else
    {
        ara[parentY] = ara[parentY]+ara[parentX];
        ara[parentX] = parentY;
    }
    --count;
}

int main()
{
    int test, max;
    char n1, n2, i;
    char str[3];

    cin >> test;

    while(test--)
    {
        cin >> n1;
        max = (int)n1-64;
        count = max;

        for(i = 1; i<=max; i++)
            ara[i] = -1;

        cin.ignore();
        while(1)
        {
            cin.getline(str, 3);

            if(str[0] == '\0')
                break;

            Union((int)str[0]-64, (int)str[1]-64, max);
        }

        if(!test)
            cout << count << endl;
        else
            cout << count << "\n\n";
    }

    return 0;
}
