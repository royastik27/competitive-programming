/**
 * UVa 101 - The Blocks Problem
 * Time: 
 * AUTHOR: Astik Roy
**/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define LIM 25

int parent[LIM];

int find_parent(int x)
{
    if(parent[x] == -1) return x;

    return find_parent(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);

    int nBlocks;

    cin >> nBlocks;

    int parent[nBlocks], a, b, pa, pb;
    vector <int> pos[nBlocks];
    register int i;
    char cmd1[5], cmd2[5];

    // initializing
    for(i = 0; i < nBlocks; ++i) {
        parent[i] = -1;
        pos[i].push_back(i);
    }


    while(cin >> cmd1 && !strcmp(cmd1, "quit")) {
        cin >> a >> cmd2 >> b;

        pa = find_parent(a);
        pb = find_parent(b);

        if(strcmp(cmd2, "onto") == 0) {
            // returning blocks top of the block b
            for(i = 0; pos[pa][i] != b; ++i);

            for(i = i + 1; i < pos[pa].size(); ++i)
                pos[pa][i]
        }

                
        if(strcmp(cmd1, "move") == 0) {
            //
        }
        else { // pile
            //
        }
    }

    return 0;
}
