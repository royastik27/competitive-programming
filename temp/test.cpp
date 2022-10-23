#include <iostream>
#include <cstring>
 
using namespace std;
 
#define LIM 300001
int winner[LIM], tree[LIM*4], n, leftVal, rightVal, val;
 
void fight(int b, int e, int node = 1)
{
    // out of range and base case
    if(b > rightVal || e < leftVal || tree[node]) return;
 
    // For leaf nodes
    if(b == e)
    {
        if(b != val)
            tree[node] = winner[b] = val;
 
        return;
    }
 
    // recursive calls
    int mid = (b + e) / 2;
    int leftNode = node * 2;
    int rightNode = leftNode + 1;
 
    fight(b, mid, leftNode);
    fight(mid+1, e, rightNode);
 
    if(tree[leftNode] == tree[rightNode]) tree[node] = tree[leftNode];
 
    return;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    
    int nFights;
 
    cin >> n >> nFights;
 
    memset(winner, 0, (n+1)*sizeof(int));
    memset(tree, 0, (n+1)*4*sizeof(int));
 
    while(nFights--)
    {
        cin >> leftVal >> rightVal >> val;
        fight(1, n);
    }
 
    for(int i = 1; i <= n; ++i)
        cout << winner[i] << ' ';
    cout << '\n';
 
    return 0;
}