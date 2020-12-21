/*
* UVA 10127 - Ones
* Author: Eng. Astik Roy
*/

#include <iostream>

using namespace std;

int main(){

    int num, res, multiple;

    while(cin >> num){

        res = 0;
        multiple = 0;

        while(num){ //for the case 0
            multiple = multiple*10 + 1;
            ++res;

            multiple%=num;

            if(!multiple)
                break;
        }

        cout << res << '\n';
    }

    return 0;
}
