/**
 * Codeforces Beta Round #3
 * Problem A - Shortest path of the king
 * Time: 
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <queue>

using namespace std;

int drow, dcol, cnt;
queue <string> moves;

int move(int i, int j)
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
        return dist;
    }
    // for same column
    else if(j == dcol) {
        int dist;
        if(dcol > j) { // right
            dist = dcol - j;
            for(int i = 0; i < dist; ++i)
                moves.push("R");
        }
        else { // left
            dist = j - dcol;
            for(int i = 0; i< dist; ++i)
                moves.push("L");
        }
        return dist;
    }

    // Diagonal moves
    if(dcol > j) {  // up
        if(drow > i) {
            moves.push("RU");
            return 1 + move(i+1, j+1);
        }
        else {
            moves.push("LU");
            return 1 + move(i-1, j+1);
        }
    }
    else { // down
        if(drow > i) {
            moves.push("RD");
            return 1 + move(i+1, j-1);
        }
        else {
            moves.push("LD");
            return 1 + move(i-1, j-1);
        }
    }
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

    cout << "SRC:\t" << srow << ' ' << scol << '\n';
    cout << "DEST:\t" << drow << ' ' << dcol << '\n';

    cout << move(srow, scol) << '\n';
    while(!moves.empty()) {
        cout << moves.front() << '\n';
        moves.pop();
    }

    return 0;
}
