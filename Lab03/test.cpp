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

typedef struct temp
{
    int head;
    list_t* line;
    struct temp* next;
}
temp_t;

int main(void)
{
    int  n, m, i, j, temp, times;
    int  end, flag, last=0;
    int* head;
    int* tail;
    char command;
    list_t* ptr;
    list_t* rptr;
    list_t* lptr = NULL;
    list_t* chain;

    cin >> n >> times;
    head = (int*)malloc(sizeof(int)*n);
    tail = (int*)malloc(sizeof(int)*n);
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
                //rptr->next = NULL;

                for (j=0; j<n; j++)
                {
                    if (tail[j] == m)
                    {
                        flag = 1;
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
                            flag = 2;
                            end = tail[j];
                            break;
                        }
                    }                    
                }

                ptr = rptr;
                lptr = rptr;
                if (flag == 1)
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
                else if (flag == 2)
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
        //cout << rptr->num << "  back: " << rptr->back << "  now: " << rptr << "  next: " << rptr->next << '\n';
    }

    for (ptr=chain; ptr!=rptr; ptr=ptr->next)
    {
        cout << ptr->num << '\n';
    }

    return 0;
}