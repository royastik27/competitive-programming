/**
* SPOJ ETF - Euler Totient Function
* Time: 70 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define LIMIT 1000000

int phi[LIMIT+1];
bool isPrime[LIMIT+1];

void seivePhi(){

    int i, j;

    for(i = 1; i<=LIMIT; ++i){
        phi[i] = i;
        isPrime[i] = true;
    }

    for(i = 2; i<=LIMIT; i+=2){
        phi[i] = phi[i] / 2;
        isPrime[i] = false;
    }


    for(i = 3; i<=LIMIT; i+=2){

        if(isPrime[i]){

            for(j = i; j<=LIMIT; j+=i){

                isPrime[j] = false;
                phi[j] = phi[j] / i * (i-1);
            }
        }
    }
}

int main(){

    int test, num;

    seivePhi();

    cin >> test;

    while(test--){

        cin >> num;

        cout << phi[num] << '\n';
    }

    return 0;
}
