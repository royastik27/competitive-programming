/**
* UVA 11332 - Summing Digits (Using Recursion)
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int summingDigit(int n){
    if(n < 10)
        return n;

    return  summingDigit((n%10) + n/10);
}

int main(){

    int number;

    while(1){
        cin >> number;
        if(!number) break;

        cout << summingDigit(number) << '\n';
    }

    return 0;
}
