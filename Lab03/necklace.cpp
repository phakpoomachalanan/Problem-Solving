#include <iostream>
#include <list>

using namespace std;

typedef struct node
{
    int     num;
    struct node* next;
}
list_t;

int size(list_t* list);

int main(void)
{
    int n, i, head, tail, j, flag=0;
    list_t*  ptr;
    list_t*  head_ptr;
    list_t*  tail_ptr;
    list_t** lace;

    cin >> n;
    lace = (list_t**)malloc(sizeof(list_t)*n);

    for (i=0; i<n; i++)
    {
        lace[i] = (list_t*)malloc(sizeof(list_t));
        lace[i]->num = i+1;
        lace[i]->next = NULL;
    }
    for (i=0; i<n-1; i++)
    {
        cin >> head >> tail;
        for (j=0; j<n; j++)
        {
            for (ptr=lace[j]; ptr!=NULL; ptr=ptr->next)
            {
                if (ptr->num == tail)
                {
                    flag = 1;
                    tail_ptr = ptr;
                    break;
                }
            }
            if (tail_ptr != NULL && flag == 1)
            {
                flag = 0;
                break;
            }
        }
        for (j=0; j<n; j++)
        {
            for (ptr=lace[j]; ptr!=NULL; ptr=ptr->next)
            {
                if (ptr->num == head)
                {
                    flag = 1;
                    head_ptr = ptr;
                    break;
                }
            }
            if (head_ptr != NULL && flag == 1)
            {
                flag = 0;
                break;
            }
        }
        ptr = tail_ptr->next;
        tail_ptr->next = head_ptr;
        while (tail_ptr->next != NULL)
        {
            tail_ptr = tail_ptr->next;
        }
        tail_ptr->next = ptr;
        lace[head-1] = NULL;
    }
    for (i=0; i<n; i++)
    {
        if (lace[i] != NULL)
        {
            for (ptr=lace[i]; ptr!=NULL; ptr=ptr->next)
            {
                cout << ptr->num << ' ';
            }
            break;
        }
    }
    cout << '\n';

    return 0;
}

int size(list_t* list)
{
    return list == NULL ? 0 : 1 + size(list->next);
}