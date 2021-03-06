/**
* SPOJ FACT0 - Integer Factorization (15 digits)
* Optimized Solution
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

void factorize(long long int n){

    long long int i, prime, primeCount = 0;
    int count = 0;

    if(n%2 == 0){
        prime = 2;
        ++primeCount;
        while(n%2 == 0){
            ++count;
            n /= 2;
        }

        cout << prime << '^' << count;
    }

    // all prime factors up to square root of n
    for(i = 3; i*i<=n; i+=2){
        if(n%i == 0){
            prime = i;
            ++primeCount;
            count = 0;
            while(n%i == 0){
                n /= i;
                ++count;
            }

            if(primeCount > 1) cout << ' ';
            cout << prime << '^' << count;
        }
    }

    // there is only one prime factor
    // which is greater than the square root of n
    if(n > 1){
        ++primeCount;
        if(primeCount > 1) cout << ' ';
        cout <<  n << '^' << 1;
    }
}

int main(){

    long long int number;

    while(1){
        cin >> number;
        if(!number) break;

        factorize(number);
        cout << '\n';
    }

    return 0;
}
