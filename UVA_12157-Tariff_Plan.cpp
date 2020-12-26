/**
* UVA 12157 - Tariff Plan
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int countMile(int n){
    return  ((n/30) + 1)*10;
}

int countJuice(int n){
    return ((n/60) + 1)*15;
}

int main(){

    int TC, nCalls, duration, k, mileTotal, juiceTotal;

    cin >> TC;

    for(k = 1; k<=TC; ++k){

        cin >> nCalls;
        mileTotal = juiceTotal = 0;
        while(nCalls--){
            cin >> duration;

            mileTotal += countMile(duration);
            juiceTotal += countJuice(duration);
        }

        cout << "Case " << k << ": ";
        if(mileTotal < juiceTotal)
            cout << "Mile " << mileTotal << '\n';
        else if(mileTotal > juiceTotal)
            cout << "Juice " << juiceTotal << '\n';
        else
            cout << "Mile Juice " << juiceTotal << '\n';
    }

    return 0;
}
