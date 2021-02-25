/**
* Codeforces Contest 988
* Codeforces Round #486 (Div. 3)
* Problem A - Diverse Team
* Time: 31 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 100

int Map[LIMIT + 1];

int main()
{
    int nStudents, toChoose, rating, indices[LIMIT], i, j;

    cin >> nStudents >> toChoose;

    for(i = 1, j = 0; i <= nStudents; ++i)
    {
        cin >> rating;

        if(!Map[rating])
            indices[j++] = i;

        ++Map[rating];
    }

    if(j >= toChoose)
    {
        cout << "YES\n";
        for(i = 0; i < toChoose; ++i)
        {
            if(i) cout << ' ';
            cout << indices[i];
        }
        cout << '\n';
    }
    else
        cout << "NO\n";

    return 0;
}
