#include <iostream>
#include <vector>

using namespace std;

typedef struct node
{
    int  num;
    bool reverse;
    struct node* next;
    struct node* back;
}
list_t;

list_t* rptr;
list_t* chain[100001];

void go_forward();
void go_backward();
void go_next();
void go_back();

int main(void)
{
    int  times, n, m, l;
    int  i, j;
    int  last=0;
    int* path;
    char command;
    list_t* lptr = NULL;
    list_t* nptr;

    cin >> l >> times;
    path = new int[n];

    for (i=0; i<l; i++)
    {
        cin >> m;

        chain[last] = new list_t;
        nptr = chain[last];
        for (j=last; j<last+m; j++)
        {
            nptr->back = lptr;
            nptr->next = new list_t;
            nptr->num = j;
            nptr->reverse = false;
            lptr = nptr;
            nptr = nptr->next;
        }
        free(nptr);
        lptr->next = NULL;

        last += m;
    }

    for (i=0; i<times; i++)
    {
        cin >> command;
        switch (command)
        {
            case 'F':
                go_forward();
                break;
            case 'B':
                go_backward();
            case 'C':
                cin >> n;
                path[i] = rptr->num;
                break;
        }
    }

    return 0;
}

void go_forward()
{
    if (rptr->reverse)
    {
        go_back();
    }
    else
    {
        go_next();
    }
}

void go_backward()
{
    if (rptr->reverse)
    {
        go_next();
    }
    else
    {
        go_back();
    }
}

void go_next()
{
    if (rptr->next != NULL)
    {
        rptr = rptr->next;
    }
}

void go_back()
{
    if (rptr->back != NULL)
    {
        rptr = rptr->back;
    }
}