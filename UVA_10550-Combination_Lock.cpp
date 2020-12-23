./**
* UVA 10550 - Combination Lock
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

#define UNIT 9

int clockwise(int a, int b){

    if(a < b)
        return (a - b + 40)*UNIT;

    return (a - b)*UNIT;
}

int anticlockwise(int a, int b){

    if(a > b)
        return (b - a + 40)*UNIT;

    return (b - a)*UNIT;
}

int main(){

    int initial, first, second, third, res;

    while(1){

        cin >> initial >> first >> second >> third;

        if(!initial && !first && !second && !third)
            break;

        res = 1080;
        res += clockwise(initial, first) + anticlockwise(first, second) + clockwise(second, third);

        cout << res << '\n';
    }

    return 0;
}
