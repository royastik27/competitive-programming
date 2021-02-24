/**
* HackerRank - Recursive Digit Sum
* Time: 349 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>

using namespace std;

#define LIMIT 100000

char num[LIMIT];

long long int charSum(int low, int high){

    if(low == high){
        return (int)num[low]-48;
    }
    int mid = (high+low)/2;

    return charSum(low, mid) + charSum(mid+1, high);
}

long long int digitSum(long long int n){

    long long int sum = 0, temp = n;

    while(n){
        sum+= n%10;
        n/=10;
    }

    if(sum == temp)
        return sum;

    return digitSum(sum);
}

int main()
{
    int repeat;
    long long int sum;

    cin >> num >> repeat;

    sum = charSum(0, strlen(num)-1);
    sum*=repeat;

    cout << digitSum(sum) << '\n';

    return 0;
}
