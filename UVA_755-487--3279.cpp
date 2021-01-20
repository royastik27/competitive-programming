/**
* UVA 755 - 487--3279 (Using Trie)
* Rank: 450
* Time: 290 ms
* AUTHOR: Eng. Astik Roy
**/

#include <iostream>

using namespace std;

struct Trie{
    struct Trie * next[10];
    int count = 0;
};

typedef struct Trie Trie;

Trie * root;

int nDuplicates;
char str[101];

int getDigit(char ch)
{
    if(ch <= '9')
        return ch-'0';
    else if(ch == 'S')
        return 7;
    else if(ch == 'V')
        return 8;
    else if(ch == 'Y')
        return 9;
    else
        return (ch-'A')/3 + 2;
}

Trie * createTrie()
{
    Trie * newTrie = new Trie;
    int i;

    for(i = 0; i<10; ++i)
        newTrie->next[i] = NULL;

    return newTrie;
}

Trie * insertTrie(Trie * state, int digit)
{
    Trie * newState = state->next[digit];

    if(newState == NULL)
        newState = createTrie();

    return state->next[digit] = newState;
}

void insert(char str[])
{
    int i, digit;
    Trie * state = root;

    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == '-')
            continue;

        // 1. map character to digit
        digit = getDigit(str[i]);

        // 2. insert digit to trie
        state = insertTrie(state, digit);
    }
    ++(state->count);
}

void traverse(Trie * state, int position)
{
    if(position == 8)
    {
        if(state->count > 1)
        {
            str[position] = '\0';
            cout << str << ' ' << state->count << '\n';
            ++nDuplicates;
        }
        delete state;
        return;
    }

    int i;
    for(i = 0; i<10; ++i)
    {
        if(state->next[i] != NULL)
        {
            // for printing a hyphen
            if(position == 3)
            {
                str[position] = '-';
                ++position;
            }
            str[position] = i + '0';

            traverse(state->next[i], position+1);
        }
    }

    // delete operation after traversing
    delete state;
}

int main()
{
    int TC, nNumbers, i;

    cin >> TC;

    while(TC--)
    {
        cin >> nNumbers;

        //initializing
        nDuplicates = 0;
        root = createTrie();

        while(nNumbers--)
        {
            cin >> str;
            insert(str);
        }

        traverse(root, 0);

        if(!nDuplicates)
            cout << "No duplicates.\n";

        // print a blank line between outputs
        if(TC) cout << '\n';
    }

    return 0;
}
