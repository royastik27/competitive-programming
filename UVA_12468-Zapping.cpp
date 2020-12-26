/**
* UVA 12468 - Zapping
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n1, n2, res1, res2;

    while(1){
        cin >> n1 >> n2;
        if(n1 == -1)
            break;

        res1 = abs(n1-n2);
        res2 = 100 - res1;

        if(res1 < res2)
            cout << res1 << '\n';
        else
            cout << res2 << '\n';
    }

    return 0;
}
