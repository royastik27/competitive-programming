/**
* UVA 10407 - Simple Division
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if(b == 0)
        return a;

    return GCD(b, a%b);
}

int main()
{
    int prev, curr, res;

    while(1)
    {
         cin >> prev;

         if(!prev) break;

         cin >> curr;
         res = prev - curr;

         while(1)
         {
             cin >> curr;

             if(!curr) break;

             res = GCD(res, prev-curr);

             prev = curr;
         }

         if(res < 0)
            res = 0 - res;

         cout << res << '\n';
    }

    return 0;
}
