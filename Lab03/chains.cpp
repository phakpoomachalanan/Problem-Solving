#include <iostream>
#include <list>

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
    int  end, flag, last=0;
    int* head;
    int* tail;
    int* path;
    char command;
    list_t* ptr;
    list_t* rptr;
    list_t* lptr = NULL;
    list_t* chain;
    list_t* tmp;
    list<list_t*> cut; 
    list<list_t*>::iterator itr;
    list<list_t*>::iterator litr;

    cin >> n >> times;
    head = (int*)malloc(sizeof(int)*n);
    tail = (int*)malloc(sizeof(int)*n);
    path = (int*)malloc(sizeof(int)*times);
    tmp = (list_t*)malloc(sizeof(list_t));
    chain = (list_t*)malloc(sizeof(list_t));

    for (i=0; i<n; i++)
    {
        head[i] = last + 1;
        cin >> m;
        tail[i] = last + m;
        last += m;
        if (i == 0)
        {
            ptr = chain;
            for (j=0; j<m; j++)
            {
                ptr->next = (list_t*)malloc(sizeof(list_t));
                ptr->back = lptr;
                ptr->num = j+1;
                lptr = ptr;
                ptr = ptr->next;
            }
            free(ptr);
            lptr->next = NULL;
        }
    }

    rptr = chain;

    for (i=0; i<times; i++)
    {
        cin >> command;
        //cout << rptr->num << "  back: " << rptr->back << "  now: " << rptr << "  next: " << rptr->next << '\n';
        switch(command)
        {
            case 'F':
                if (rptr->next != NULL)
                {
                    rptr = rptr->next;
                }
                break;
            case 'B':
                if (rptr->back != NULL)
                {
                    rptr = rptr->back;
                }
                break;
            case 'C':
                cin >> m;
                flag = 0;
                if (rptr->next != NULL)
                {
                    cut.push_back(rptr->next);
                    /*tmp = (list_t*)malloc(sizeof(list_t));
                    ptr=rptr->next;
                    while (ptr->next != NULL)
                    {
                        cout << ptr->num;
                        ptr=ptr->next;
                    }
                    for (; ptr!=NULL; ptr=ptr->back)
                    {
                        tmp->next = (list_t*)malloc(sizeof(list_t));
                        tmp->num = ptr->num;
                        tmp->back = ptr->next;
                        tmp = tmp->next;
                    }*/
                }
                /*ptr = tmp->back;
                free(ptr->next);
                tmp->back->next = NULL;
                rptr->next = NULL;*/

                for (itr=cut.begin(), j=0; itr!=cut.end(); itr++, j++)
                {
                    ptr = *itr;
                    if (ptr->num == m)
                    {
                        if (j%2 == 0)
                        {
                            litr = itr;
                            advance(itr, 1);
                        }
                        else if (j%2 == 1)
                        {
                            litr = itr;
                            advance(itr, -1);
                        }
                        cut.erase(litr);
                        cut.erase(itr);
                        rptr->next = ptr;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    rptr = rptr->next;
                    break;
                }

                for (j=0; j<n; j++)
                {
                    if (tail[j] == m)
                    {
                        flag = 2;
                        end = head[j];
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (j=0; j<n; j++)
                    {
                        if (head[j] == m)
                        {
                            flag = 3;
                            end = tail[j];
                            break;
                        }
                    }                    
                }

                ptr = rptr;
                lptr = rptr;
                if (flag == 2)
                {
                    for (j=m; j>=end; j--)
                    {
                        ptr->next = (list_t*)malloc(sizeof(list_t));
                        ptr = ptr->next;
                        ptr->back = lptr;
                        ptr->num = j;
                        lptr = ptr;
                    }
                    free(ptr);
                }
                else if (flag == 3)
                {
                    for (j=m; j<=end; j++)
                    {
                        ptr->next = (list_t*)malloc(sizeof(list_t));
                        ptr = ptr->next;
                        ptr->back = lptr;
                        ptr->num = j;
                        lptr = ptr;
                    }
                    free(ptr);
                }
                rptr = rptr->next;
                break;
        }
        path[i] = rptr->num;
        //cout << rptr->num << "  back: " << rptr->back << "  now: " << rptr << "  next: " << rptr->next << '\n';
    }

    /*for (ptr=chain; ptr!=rptr; ptr=ptr->next)
    {
        cout << ptr->num << '\n';
    }*/

    for (i=0; i<times; i++)
    {
        cout << path[i] << '\n';
    }

    return 0;
}