/**
* UVA 102 - Ecological Bin Packing
* Time: 40 ms
* AUTHOR: Astik Roy
**/

#include <iostream>

using namespace std;

#define INF 2147483647

int bootle[9], sum[3];

int get_single_moves(char color, int bin_no)
{
    int index = bin_no * 3;

    if(color == 'B')
        return sum[bin_no] - bootle[index];
    else if(color == 'G')
        return sum[bin_no] - bootle[index + 1];
    else
        return sum[bin_no] - bootle[index + 2];
}

int get_moves(char str[])
{
    int moves = 0;

    for(int i = 0; i < 3; ++i)
        moves += get_single_moves(str[i], i);

    return moves;
}

int main()
{
    int i, data, min_moves, move_index;
    char move[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };

    while(cin >> bootle[0])
    {
        for(i = 1; i < 9; ++i)
            cin >> bootle[i];

        for(int j = 0, i = 0; i < 3; ++i, j+=3)
            sum[i] = bootle[j] + bootle[j+1] + bootle[j+2];

        min_moves = INF;
        move_index = 0;
        for(i = 0; i < 6; ++i)
        {
            data = get_moves(move[i]);
            if(data < min_moves){
                min_moves = data;
                move_index = i;
            }
        }

        cout << move[move_index] << ' ' << min_moves << '\n';
    }

    return 0;
}
