/**
* CodeCraft-21 and Codeforces Round #711 (Div. 2)
* Problem A - GCD Sum
* Time: 62 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
 
using namespace std;
 
int sum_of_digits(long long int num)
{
    int sod = 0;
 
    while(num)
    {
        sod += num % 10;
 
        num /= 10;
    }
 
    return sod;
}
 
long long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;
 
    return gcd(b, a%b);
}
 
int main()
{
    int TC, sod;
    long long int num;
 
    cin >> TC;
 
    while(TC--)
    {
        cin >> num;
 
        sod = sum_of_digits(num);
 
        while(gcd(num, sod) == 1)
        {
            ++num;
 
            sod = sum_of_digits(num);
        }
 
        cout << num << '\n';
    }
 
    return 0;
}
