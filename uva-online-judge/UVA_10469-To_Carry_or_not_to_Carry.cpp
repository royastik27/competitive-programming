/**
 * UVa 10469 - To Carry or not to Carry
 * AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int a, b;

    while(cin >> a >> b) {
        cout << (a ^ b) << '\n';
    }

    return 0;
}
