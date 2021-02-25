/**
* Codeforces Problem 535
* Codeforces Round #299 (Div. 2)
* Problem A - Tavas and Nafas
* Time: 15 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char first[20][10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    char second[10][8] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    int num;

    while(cin >> num)
    {
        if(num <= 19)
            cout << first[num] << '\n';
        else
        {
            cout << second[num / 10];

            if(num % 10 != 0)
                cout << '-' << first[num % 10];

            cout << '\n';
        }
    }

    return 0;
}
