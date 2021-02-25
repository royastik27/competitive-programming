/**
* UVA 12554 - A Special "Happy Birthday" Song!!!
* Totally Unique Solution
* Uses Less Memory
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main(){

    char song[4][9] = { "Happy", "birthday", "to", "you" };
    char person[100][101];
    int nPersons, i, j, temp;

    cin >> nPersons;
    for(i = 0; i<nPersons; ++i)
            cin >> person[i];

    temp = 11;
    // sung every person once
    for(i = 0, j = 0; i<nPersons; ++i, ++j){

        cout << person[i] << ": ";
        // song logic for the repetation of "Rujia"
        if(j == temp){
            cout << "Rujia" << '\n';
            temp += 16;
        }
        else
            cout << song[j%4] << '\n';
    }

    // if song is not completed
    while(j%16 != 0){
        cout << person[i%nPersons] << ": ";

        if(j == temp){
            cout << "Rujia" << '\n';
            temp += 16;
        }
        else
            cout << song[j%4] << '\n';

        ++i;
        ++j;
    }

    return 0;
}
