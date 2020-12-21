/**
* UVA 369 - Combinations
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int n, m, large, small, i, j;
    double res;

    while(cin >> n >> m){

        if(!n && !m)
            break;

        if(n == m)
            res = 1;
        else{
            if(n-m > m){
                large = n-m;
                small = m;
            }
            else{
                large = m;
                small = n-m;
            }

            res = 1;
            for(i = n, j = small; i > large, j > 0; i--, j--){
                res = res * ((double)i/j);
            }
        }

        cout << n << " things taken " << m << " at a time is " << (int)round(res) << " exactly.\n";
    }

    return 0;
}
