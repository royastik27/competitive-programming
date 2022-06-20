#include <iostream>
#include <cstring>
#include <bitset>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define LIM 101

bool checkBit(int n, int pos)
{
    return n & (1 << pos);
}

void setBit(int * n, int pos) { *n |= (1 << pos); }

void unsetBit(int * n, int pos) { *n ^= (1 << pos); }

void printPosition(int ara[], int n)
{
    int i, j;

    cout << "positions:\n";
    for(i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for(j = 1; j <= n; ++j)
        {
            if(checkBit(ara[i], j)) cout << j << ' ';
        }
        cout << '\n';
    }
}

void swap(int * a, int * b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

void printAB(int a[], int b[], int n)
{
	cout << "Array A, B\n";
                        for(int k = 1; k <= n; ++k)
                        cout << a[k] << ' ';
                        cout << '\n';
                        for(int k = 1; k <= n; ++k)
                        cout << b[k] << ' ';
                        cout << '\n';
}

void printPositions(int posA[], int posB[], int n)
{
	int i, j;
	
	cout << "Positions of A:\n";
	for(i = 1; i <= n; ++i)
	{
		cout << i << ": ";
		for(j = 1; j <= n; ++j)
			if(checkBit(posA[i], j))
				cout << j << ' ';
			cout << '\n';
	}
	
	cout << "Positions of B:\n";
	for(i = 1; i <= n; ++i)
	{
		cout << i << ": ";
		for(j = 1; j <= n; ++j)
			if(checkBit(posB[i], j))
				cout << j << " ";
			cout << '\n';
	}

	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a[LIM], sortedA[LIM], b[LIM], sortedB[LIM], TC, n, i, j, posA[LIM], posB[LIM];
    bool impossible;
    vector <pair <int, int> > swaps;

    a[0] = b[0] = sortedA[0] = sortedB[0] = 0;
    // int k = 0;

    cin >> TC;

    while(TC--)
    {
        cin >> n;

        memset(posA, 0, (n+1)*sizeof(int));
        memset(posB, 0, (n+1)*sizeof(int));

        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sortedA[i] = a[i];
            setBit(&posA[a[i]], i);
        }

        for(i = 1; i <= n; ++i)
        {
            cin >> b[i];
            sortedB[i] = b[i];
            setBit(&posB[b[i]], i);
        }

        // SORTING
        sort(sortedA, sortedA+n+1);
        sort(sortedB, sortedB+n+1);

        // MAIN OPERATION
        impossible = false;
        
        // printPositions(posA, posB, n);

        for(i = 1; i <= n - 1; ++i)
        {
            if(a[i] == sortedA[i] && b[i] == sortedB[i])
                continue;
            else
            {
                // cout << "Mismatch: " << i << '\n';
                // check other positions of sortedA[i] that match with any position of sortedB[i]
                for(j = i + 1; j <= n; ++j)
                {
                    if(checkBit(posA[sortedA[i]], j) && checkBit(posB[sortedB[i]], j))
                    {
                       // cout << "For " << i << " found " << j << '\n';
                        
                        // update positions
                        unsetBit(&posA[a[i]], i);
                        unsetBit(&posA[a[j]], j);
                        
                        setBit(&posA[a[i]], j);
                        setBit(&posA[a[j]], i);
                        
                        unsetBit(&posB[b[i]], i);
                        unsetBit(&posB[b[j]], j);
                        
                        setBit(&posB[b[i]], j);
                        setBit(&posB[b[j]], i);
                        
                        // printPositions(posA, posB, n);

                        // swapping
                        swap(&a[i], &a[j]);
                        swap(&b[i], &b[j]);
                        
                        // printAB(a, b, n);                        
                        // printPositions(posA, posB, n);                        

                        // updating answers
                        swaps.push_back(make_pair(i, j));
                        break;
                    }
                }

                if(j > n) // not found
                {
                    //cout << "Impossible for " << i << '\n';
                    impossible = true;
                    break;
                }
            }
        }

        if(impossible) cout << -1 << '\n';
        else
        {
            cout << swaps.size() << '\n';
            for(i = 0; i < swaps.size(); ++i)
                cout << swaps[i].first << ' ' << swaps[i].second << '\n';
        }
        swaps.clear();
    }

    return 0;
}
