/**
* UVA 12503 - Robot Instructions
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main(){

    int test, nInstructions, res, i, index;
    char instruction[101], str[6];

    cin >> test;

    while(test--){

        cin >> nInstructions;

        res = 0;
        for(i = 1; i<=nInstructions; ++i){
            cin >> str;

            instruction[i] = str[0];

            if(instruction[i]== 'S'){
                cin >> str >> index;
                instruction[i] = instruction[index];
            }

            if(instruction[i] == 'L')
                --res;
            else
                ++res;
        }

        cout << res << '\n';
    }

    return 0;
}
