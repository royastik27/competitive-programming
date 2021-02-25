/**
* UVA 11078 - Open Credit System
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main(){

    int test, num, res, max, data, i;

    cin >> test;

    while(test--){

        cin >> num;

        cin >> data;

        res = -150000;
        max = data;
        for(i = 1; i<num; ++i){

            cin >> data;

            if(max - data > res)
                res = max - data;

            if(data > max)
                max = data;
        }

        cout << res << '\n';
    }

    return 0;
}
