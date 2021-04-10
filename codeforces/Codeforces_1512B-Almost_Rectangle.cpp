/**
* Codeforces Round #713 (Div. 3)
* Problem B - Almost Rectangle
* Time: 93 ms
* AUTHOR: Astik Roy
**/

#include <iostream>
#include <vector>
#include <utility>
 
using namespace std;
 
#define SIZE 400
 
int main()
{
    vector <pair <int, int> > cell;
    char field[SIZE][SIZE];
    int TC, n;
    register int i, j;
 
    cin >> TC;
 
    while(TC--)
    {
        cin >> n;
 
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cin >> field[i][j];
 
                if(field[i][j] == '*')
                    cell.push_back(make_pair(i, j));
            }
        }
 
        // finding pairs
        if(cell[0].first == cell[1].first)  // same row
        {
            if(cell[0].first == 0)
            {
                field[cell[0].first + 1][cell[0].second] = '*';
                field[cell[1].first + 1][cell[1].second] = '*';
            }
            else
            {
                field[cell[0].first - 1][cell[0].second] = '*';
                field[cell[1].first - 1][cell[1].second] = '*';
            }
        }
        else if(cell[0].second == cell[1].second)   // same column
        {
            if(cell[0].second == 0)
            {
                field[cell[0].first][cell[0].second + 1] = '*';
                field[cell[1].first][cell[1].second + 1] = '*';
            }
            else
            {
                field[cell[0].first][cell[0].second - 1] = '*';
                field[cell[1].first][cell[1].second - 1] = '*';
            }
        }
        else    // diagonal
        {
            field[cell[0].first][cell[1].second] = '*';
            field[cell[1].first][cell[0].second] = '*';
        }
 
        // printing
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
                cout << field[i][j];
            cout << '\n';
        }
 
        cell.clear();
    }
 
    return 0;
}
