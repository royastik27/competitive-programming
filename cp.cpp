/**
* C++ File Runner with royastik27 (Windows)
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define DOTSIZE 61

void printArt()
{
    string company = "royastik27 Software Corporation";

    cout << "\t\t" << company << '\n';

    for(int i = 0; i < DOTSIZE; ++i)
        cout << '.';
    cout << '\n';

    return;
}

void printEnd()
{
    for(int i = 0; i < DOTSIZE; ++i)
        cout << '.';
    cout << "\n\t\t\tHappy Coding\n";
}

int main(int argc, char * argv[])
{
    printArt();

    if(argc == 1)
    {
        cout << "Hey! No input file.\n";
        return 0;
    }

    char * op = argv[1], * fileName;

    if(!strcmp(op, "c"))
    {
        if(argc == 2)
        {
            cout << "Hey! No input file.\n";
            printEnd();
            return 0;
        }

        fileName = argv[2];

        char command[100] = "g++ -std=c++0x ";

        strcat(command, fileName);
        strcat(command, ".cpp -o ");
        strcat(command, fileName);
        
        // COMPILING THE FILE
        system(command);
    }
    else fileName = op;

    // EXECUTING THE FILE
    system(fileName);

    printEnd();

    return 0;
}