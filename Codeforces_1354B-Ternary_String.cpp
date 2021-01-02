/**
* Codeforces Contest 1354
* Problem B - Ternary String
* Time: 93 ms.
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 200001;

int maxTernary(char str[])
{
    int dis1, dis2, dis3, min, i, dis;
    dis1 = dis2 = dis3 = min = MAX;

    for(i = 0; str[i] != '\0'; ++i)
    {
        // getting current character
        switch(str[i]){
        case '1':
            dis1 = 0;
            break;
        case '2':
            dis2 = 0;
            break;
        default:
            dis3 = 0;
        }

        // distance calculation
        dis = max(dis1, dis2);
        dis = max(dis, dis3);
        ++dis;

        if(dis < min) min = dis;

        ++dis1; ++dis2; ++dis3;
    }

    if(min == MAX)
        min = 0;

    return min;
}

int main()
{

    int TC;
    char str[MAX];

    cin >> TC;

    while(TC--)
    {
        cin >> str;

        // call the function
        cout << maxTernary(str) << '\n';
    }

    return 0;
}
