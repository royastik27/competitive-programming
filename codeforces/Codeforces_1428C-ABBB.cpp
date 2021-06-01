/**
* Codeforces Raif Round 1 (Div. 1 + Div. 2)
* Problem C - ABBB
* Time: 46 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>

using namespace std;

#define LIM 200001

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TC;
    char str[LIM];
    vector <char> vec;
    register int i;

    cin >> TC;

    while(TC--)
    {
        cin >> str;

        vec.push_back(str[0]);

        for(i = 1; str[i] != '\0'; ++i) {
            if(vec.size() && str[i] == 'B')
                vec.erase(--vec.end());
            else
                vec.push_back(str[i]);
        }

        cout << vec.size() << '\n';

        vec.clear();
    }

    return 0;
}
