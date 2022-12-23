#include <iostream>

using namespace std;

typedef struct node
{
    int num;
    struct node* next;
    struct node* back;
}
list_t;

int main(void)
{
    int  n, m, i, j, temp, times;
    int  last=1;
    char command;
    list_t*  ptr; 
    list_t*  lptr;
    list_t*  dptr;
    list_t** head;
    //list_t** tail;
    list_t** chain;

    cin >> n >> times;
    chain = (list_t**)malloc(sizeof(list_t*)*n);

    for (i=0; i<n; i++)
    {
        cin >> m;
        chain[i] = (list_t*)malloc(sizeof(list_t)*m);
        ptr = chain[i];
        lptr = NULL;
        for (j=0; j<m; j++, last++)
        {
            ptr->next = (list_t*)malloc(sizeof(list_t)*m);
            ptr->num = last;
            ptr->back = lptr;
            lptr = ptr;
            ptr = ptr->next;
        }
        lptr->next = NULL;
        free(ptr);
    }
    head = (list_t**)malloc(sizeof(list_t*)*last+1);
    //tail = (list_t**)malloc(sizeof(list_t*)*last+1);
    for (i=0, j=0; i<n; i++)
    {
        head[j+1] = chain[i];
        for (ptr=chain[i]; ptr->next!=NULL; ptr=ptr->next, j++) {}
        head[++j] = ptr;
    }
    ptr = chain[0];

    for (i=0; i<times; i++)
    {
        cin >> command;
        switch(command)
        {
            case 'F':
                if (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                break;
            case 'B':
                if (ptr->back != NULL)
                {
                    ptr = ptr->back;
                }
                break;
            case 'C':
                cin >> n;
                for (dptr=ptr->next; dptr!=NULL; dptr=lptr)
                {
                    lptr = lptr->next;
                    free(dptr);
                }
                ptr->next = head[n];
                ptr = ptr->next;
                if (ptr->next == NULL)
                {
                    for (;ptr!=NULL; ptr=ptr->back)
                    {
                         
                    }
                }
                break;
        }
    }

    for (i=0; i<n; i++)
    {
        for (ptr=chain[i]; ptr!=NULL; ptr=ptr->next)
        {
            cout << ptr->num << ' ';
        }
        cout << '\n';
    }
    /*for (i=0; i<last; i++)
    {
        cout << i << ' ' << head[i] << '\n';
    }*/

    return 0;
}