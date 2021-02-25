/**
* UVA 579 - Clock hands
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int main(){

    cout << fixed;
    cout << setprecision(3);

    double hour, minute;
    double res1, res2;

    while(1){

        cin >> hour;
        getchar();
        cin >> minute;

        if(!hour && !minute)
            break;

        //convert hour to minutes
        hour *= 5;
        hour += minute*0.083333333;

        if(hour > minute)
            res1 = (60 - hour) + minute;
        else
            res1 = (60 - minute) + hour;

        res2 = abs(hour - minute);

        res1 *= 6;
        res2 *= 6;

        if(res1 < res2)
            cout << res1 << '\n';
        else
            cout << res2 << '\n';
    }

    return 0;
}
