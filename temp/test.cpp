#include <iostream>
#include <set>

using namespace std;

class Test
{
    int tata[10];

    void printMoga()
    {
        cout << "Moga: ";
        cout << tata[0] << '\n';
        return;
    }

    public:
    Test()
    {
        tata[0] = 27;
    }
    void printTata()
    {
        cout << "tata: " << tata[0] << '\n';
        printMoga();
        return;
    }
};

int main()
{
    int arr[5] = {};

    Test tok;

    tok.printTata();
    tok.printTata();

    return 0;
}