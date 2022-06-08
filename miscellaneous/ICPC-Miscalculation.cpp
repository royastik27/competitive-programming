/**
* ACM International Collegiate Programming Contest
* Asia Regional Contest, Tokyo, 2014–10–19
* Problem B - Miscalculation
* Time: 31 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

int main()
{
    char expression[18];
    long long int userRes, preRes, left2rightRes;
    int numbers[10], rear = -1, i;

    cin >> expression >> userRes;

    numbers[++rear] = left2rightRes = expression[0] - '0';

    for(i = 1; expression[i] != '\0'; i+=2)
    {
        if(expression[i] == '+')
        {
            // for precedence
            numbers[++rear] = expression[i+1] - '0';
            // for left2right
            left2rightRes += expression[i+1] - '0';
        }
        else if(expression[i] == '*')
        {
            // for precedence
            numbers[rear] *= (expression[i+1] - '0');
            // for left2right
            left2rightRes *= (expression[i+1] - '0');
        }
    }

    preRes = 0;
    for(i = 0; i<=rear; ++i)
        preRes += numbers[i];

    if(userRes == preRes && userRes == left2rightRes)
        cout << 'U' << '\n';
    else if(userRes == preRes)
        cout << 'M' << '\n';
    else if(userRes == left2rightRes)
        cout << 'L' << '\n';
    else
        cout << 'I' << '\n';

    return 0;
}
