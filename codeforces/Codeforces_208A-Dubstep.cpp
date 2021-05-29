#include <iostream>
#include <cstring>
 
using namespace std;
 
int main()
{
    char str[201], res[201];
    int i, j, len;
 
    cin >> str;
 
    len = strlen(str);
 
    i = 0;
    j = -1;
 
    // determining the first character
    if(len - i > 2 && str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B') {
        while(len - i > 2 && str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B')
            i += 3;
 
        res[++j] = str[i++];
    }
 
    while(i < len)
    {
        if(len - i > 2 && str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B') {
            if(res[j] != ' ') // for avoiding extra space
                res[++j] = ' ';
            i += 3;
        }
        else {
            res[++j] = str[i++];
        }
    }
 
    // terminating string
    if(res[j] == ' ')
        res[j] = '\0';
    else res[++j] = '\0';
 
    cout << res << '\n';
 
    return 0;
}
