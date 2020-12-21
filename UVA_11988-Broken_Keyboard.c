/**
* UVA 11988 - Broken Keyboard
* With Linked List
* AUTHOR: Eng. Astik Roy
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char ch;
    struct node * next;
};

struct node * head = NULL, * tail, * temp_head;

void add_end(char ch);
struct node * add_home(char ch, struct node * prev);
void traverse();

int main()
{
    struct node * prev;
    char line[100001];
    int len, i;
    _Bool pressedHome;

    while(scanf("%s", line)!=EOF)
    {
        len = strlen(line);
        pressedHome = 0;

        for(i = 0; i<len; i++)
        {
            if(line[i] == '[')
            {
                prev = NULL;
                pressedHome = 1;
                continue;
            }
            else if(line[i] == ']')
            {
                pressedHome = 0;
                continue;
            }

            if(pressedHome)
            {
                prev = add_home(line[i], prev);
            }
            else
            {
                add_end(line[i]);
            }
        }
        traverse();
        printf("\n");
    }

    return 0;
}

struct node * add_home(char ch, struct node * prev)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->ch = ch;

    if(prev == NULL)
    {
        ptr->next = head;
        temp_head = head;
        head = ptr;
    }
    else
    {
        ptr->next = temp_head;
        prev->next = ptr;
    }

    if(ptr->next == NULL)
        tail = ptr;

    return ptr;
};

void add_end(char ch)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    ptr->ch = ch;
    ptr->next = NULL;

    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        tail->next = ptr;
    }
    tail = ptr;
};

void traverse()
{
    struct node * temp = head, * todelete;

    while(temp != NULL)
    {
        printf("%c", temp->ch);
        todelete = temp;
        temp = temp->next;
        free(todelete);
    }
    head = NULL;
}
