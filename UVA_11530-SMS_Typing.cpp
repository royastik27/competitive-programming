/**
* UVA 11530 - SMS Typing
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main(){

    int keypressTimes[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    int TC, res, i, k;
    char str[101];

    cin >> TC;

    getchar();

    for(k = 1; k<=TC; ++k){

        cin.getline(str, 101);

        res = 0;
        for(i = 0; str[i]!='\0'; ++i){
            if(str[i] == ' ')
                ++res;
            else
                res += keypressTimes[(int)str[i] - 97];
        }

        cout << "Case #" << k << ": " << res << '\n';
    }

    return 0;
}
