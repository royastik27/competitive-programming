/**
* UVA 10140 - Prime Distance
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <math.h>

using namespace std;

#define LIMIT 1000000
#define SQRT 46350
#define MAX 2147483647

unsigned int sqPrimes[4794], primes[1000001];

void seive(){

    unsigned int i, j;
    bool isPrime[SQRT+1];

    for(i = 3; i<=SQRT; i+=2)
        isPrime[i] = true;

    sqPrimes[0] = 2;

    for(i = 3; i*i<=SQRT; i+=2){
        if(isPrime[i]){
            for(j = i*i; j<=SQRT; j+=2*i)
                isPrime[j] = false;
        }
    }

    for(i = 3, j = 1; i<=SQRT; i+=2)
        if(isPrime[i])
            sqPrimes[j++] = i;
}

int segmentedSeive(int left, int right){

    bool isPrime[right-left+1];
    unsigned int i, j, temp;

    if(left < 2)
        left = 2;

    if(right == 1)
        return 1;

    for(i = left; i<=right && i >= left; ++i)
        isPrime[i-left] = true;

    for(i = 0; sqPrimes[i] <= 46341 && sqPrimes[i]*sqPrimes[i]<=right; i++){

        temp = ceil((double)left/sqPrimes[i]);

        if(temp <= 1)
            temp = 2;

        for(j = sqPrimes[i]*temp; j<=right && j>=left; j+=sqPrimes[i]){
            isPrime[j-left] = false;
        }
    }

    for(i = left, j = 0; i<=right && i >= left; ++i){
        if(isPrime[i-left]){
            primes[j++] = i;
        }
    }

    return j;
}

int main(){

    seive();

    unsigned int left, right, i, min_dis, max_dis, a1, a2, b1, b2, diff, size;

    while(cin >> left >> right){

        size = segmentedSeive(left, right);

        max_dis = 0;
        min_dis = MAX;

        a1 = 0;

        for(i = 0; i+1<size; i++){

            diff = primes[i+1] -  primes[i];

            if(diff < min_dis){
                a1 = primes[i];
                a2 = primes[i+1];
                min_dis = diff;
            }

            if(diff > max_dis){
                b1 = primes[i];
                b2 = primes[i+1];
                max_dis = diff;
            }
        }

        if(size == 1 || !a1){
            cout << "There are no adjacent primes.\n";
            continue;
        }

        cout << a1 << ',' << a2 << " are closest, " << b1 << ',' << b2 << " are most distant.\n";
    }

    return 0;
}
