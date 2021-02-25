/**
* UVA 900 - Brick Wall Patters
* The pattern is actually the Fibonacci sequence
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

long long int fib[51];

void readyFib(){

    int i;

    fib[1] = 1;
    fib[2] = 2;
    for(i = 3; i<=50; ++i)
        fib[i] = fib[i-2] + fib[i-1];
}

int main(){

    readyFib();

    int length;

    while(1){

        cin >> length;

        if(!length) break;

        cout << fib[length] << '\n';
    }

    return 0;
}
