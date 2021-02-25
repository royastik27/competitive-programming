/**
* UVA 12015 - Google is Feeling Lucky (Iterating twice)
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

typedef struct URLtype{

    int relevance;
    char name[101];
}URLtype;

int main(){

    int TC, max, k, i;
    URLtype URL[10];

    cin >> TC;
    for(k = 1; k<=TC; ++k){

        max = 0;
        for(i = 0; i<10; ++i){
            cin >> URL[i].name >> URL[i].relevance;

            if(URL[i].relevance > max)
                max = URL[i].relevance;
        }

        cout << "Case #" << k << ":\n";
        for(i = 0; i<10; ++i){
            if(URL[i].relevance == max)
                cout << URL[i].name << '\n';
        }
    }

    return 0;
}
