/**
* UVA 11942 - Lumberjack Sequence
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main(){

    int TC, prev, data, i;
    bool isAsc, isDec;

    cout << "Lumberjacks:\n";
    cin >> TC;

    while(TC--){

        isAsc = isDec = false;

        cin >> prev;
        for(i = 1; i<10; ++i){
            cin >> data;

            if(data > prev) isAsc = true;
            else isDec = true;

            prev = data;
        }

        if(isAsc && isDec)
            cout << "Unordered\n";
        else
            cout << "Ordered\n";
    }

    return 0;
}
