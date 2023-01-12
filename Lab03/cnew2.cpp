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

        }
    }

    for (i=0, j=0; i<l; i++)
    {
        for (nptr=chain[j]; nptr!=NULL; nptr=nptr->next, j++)
        {
            cout << nptr->num << ' ';
        }
        cout << '\n';
    }
}