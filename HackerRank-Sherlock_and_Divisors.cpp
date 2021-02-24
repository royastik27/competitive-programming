/**
* HackerRank - Sherlock and Divisors
* Time: 263 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    int test, num, div, i, res;

    cin >> test;

    while(test--){

        cin >> num;

        res = 0;

        if(num%2 == 1){
            cout << res << '\n';
            continue;
        }
        else{

            for(i = 1; i*i<=num; i++){

                if(num%i == 0){
                    div = num/i;

                    if(div%2 == 0){
                    ++res;
                    }
                    if(i%2 == 0){
                        ++res;
                    }

                    if(div == i)
                        --res;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}
