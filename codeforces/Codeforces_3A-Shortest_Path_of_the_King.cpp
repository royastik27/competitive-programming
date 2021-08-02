/**
 * Codeforces Beta Round #3
 * Problem A - Shortest path of the king
 * Time: 62 ms
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

int drow, dcol;
queue <string> moves;

void move(int i, int j)
{
    // for same row
    if(i == drow) {
        int dist;
        if(dcol > j) {  // up
            dist = dcol - j;
            for(int i = 0; i < dist; ++i)
                moves.push("U");
        }
        else {  // down
            dist = j - dcol;
            for(int i = 0; i < dist; ++i)
                moves.push("D");
        }
    }
    // for same column
    else if(j == dcol) {
        int dist;
        if(drow > i) { // right
            dist = drow - i;
            for(int i = 0; i < dist; ++i)
                moves.push("R");
        }
        else { // left
            dist = i - drow;
            for(int i = 0; i < dist; ++i)
                moves.push("L");
        }
    }
    // Diagonal moves
    else if(dcol > j) {  // up
        if(drow > i) {
            moves.push("RU");
            move(i+1, j+1);
        }
        else {
            moves.push("LU");
            move(i-1, j+1);
        }
    }
    else { // down
        if(drow > i) {
            moves.push("RD");
            move(i+1, j-1);
        }
        else {
            moves.push("LD");
            move(i-1, j-1);
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int srow, scol;
    char inp[3];

    cin >> inp;
    srow = inp[0] - 'a' + 1;
    scol = inp[1] - '0';

    cin >> inp;
    drow = inp[0] - 'a' + 1;
    dcol = inp[1] - '0';

    move(srow, scol);
    cout << moves.size() << '\n';
    while(!moves.empty()) {
        cout << moves.front() << '\n';
        moves.pop();
    }

    return 0;
}
