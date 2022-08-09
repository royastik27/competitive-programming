#include <iostream>

using namespace std;

// bool isPalindrome()
// {
//     int i = 0, j = len - 1;

//     while(i < j)
//     {
//         if(!str[i]) ++i;
//         else if(!str[j]) --j;
//         else if(str[i] != str[j]) return false;
//         else { ++i, --j; }
//     }

//     return true;
// }

int main()
{
    string str = "Astik";

    cout << str << '\n';
    cout << str.length() << '\n';

    str[1] = 0;
    cout << str << '\n';
    cout << str.length() << '\n';

    return 0;
}