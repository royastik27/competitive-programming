/**
* NAME: Data Structures - String Processing
* AUTHOR: Astik Roy
* DATE: 07-06-2022
**/

#include <iostream>

using namespace std;

int INDEX(string text, string pattern)
{
    if(pattern.length() > text.length()) return 0;

    int i, j;

    for(i = 0; i < text.length() - pattern.length() + 1; ++i)
    {
        for(j = 0; j < pattern.length(); ++j)
        {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == pattern.length()) return i + 1;
    }

    return 0;
}

string INSERT(string text, int position, string str)
{
    return text.substr(0, position - 1) + str + text.substr(position - 1, text.length() - position + 1);
}

string DELETE(string text, int position, int length)
{
    if(position == 0) return text;

    return text.substr(0, position - 1) + text.substr(position+length-1, text.length() - position - length + 1);
}

string DELETEALL(string text, string pattern)
{
    int index = INDEX(text, pattern);

    while(index != 0)
    {
        text = DELETE(text, index, pattern.length());
        index = INDEX(text, pattern);
    }

    return text;
}

string REPLACE(string text, string pattern1, string pattern2)
{
    int index = INDEX(text, pattern1);

    if(index)
    {
        text = DELETE(text, index, pattern1.length());
        text = INSERT(text, index, pattern2);
    }

    return text;
}

string REPLACEALL(string text, string pattern1, string pattern2)
{
    int index = INDEX(text, pattern1);

    while(index != 0)
    {
        text = REPLACE(text, pattern1, pattern2);
        index = INDEX(text, pattern1);
    }

    return text;
}

int main()
{
    // DRIVER CODE

    return 0;
}
