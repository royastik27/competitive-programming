/**
* UVA 119 - Greedy Gift Givers
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

struct type{
    char name[13];
    int amount;
}person[10];

int main(){

    int nPersons, i, j, index, amount, res, nGifts, TC = 0;
    char name[13];

    while(cin >> nPersons){

        ++TC;
        // getting all input and initializing
        for(i = 0; i<nPersons; ++i){
            cin >> person[i].name;
            person[i].amount = 0;
        }

        // for every gift query
        for(i = 0; i<nPersons; ++i){

            cin >> name;
            for(j = 0; j<nPersons; ++j){
                if(!strcmp(name, person[j].name))
                    break;
            }

            cin >> amount >> nGifts;
            if(nGifts != 0)
                res = amount / nGifts;
            person[j].amount -= res * nGifts;


            for(j = 0; j<nGifts; ++j){
                cin >> name;
                for(index = 0; index<nPersons; ++index){
                    if(!strcmp(name, person[index].name)){
                        person[index].amount += res;
                        break;
                    }
                }
            }
        }

        //printing the result
        if(TC > 1)
            cout << '\n';
        for(i = 0; i<nPersons; ++i){
            cout << person[i].name << ' ' << person[i].amount << '\n';
        }
    }

    return 0;
}
