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
    list_t* lptr;
    list_t* pptr;

    cin >> l >> times;
    path = new int[n];

    for (i=0; i<l; i++)
    {
        cin >> m;

        chain[last] = new list_t;
        lptr = NULL;
        for (j=last; j<last+m; j++)
        {
            chain[j]->back = lptr;
            chain[j+1] = new list_t;
            chain[j]->next = chain[j+1];
            chain[j]->num = j;
            chain[j]->reverse = false;
            lptr = chain[j];
            //cout << chain[j]->num << ' ' << chain[j] << ' ';
        }
        //cout << "\n----" << lptr->num << ' ' << nptr->num << '\n';
        free(chain[j+1]);
        lptr->next = NULL;

        last += m;
    }

    rptr = chain[0];
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
                break;
            case 'C':
                cin >> n; n--;
                // cout << n << " " << chain[n] << endl;
                
                pptr = rptr;

                if (pptr->reverse)
                {
                    if (pptr->back != NULL)
                    {
                        // cout << "1.0   " << pptr->next->num << endl;
                        pptr->back->next = NULL;
                        pptr->back = NULL;
                    }                    
                }
                else
                {
                    if (pptr->next != NULL)
                    {
                        // cout << "1.0   " << pptr->next->num << endl;
                        pptr->next->back = NULL;
                        pptr->next = NULL;
                    }
                }

                
                // cout << "1.1   " << chain[n]->num << endl;
                if (chain[n]->next == NULL)
                {
                    // tail case
                    // cout << "1.1   " << chain[n]->next << endl;
                    if (chain[n]->back != NULL)
                    {
                        // reverse all chain[n]'s chain
                        for (pptr=chain[n]; pptr!=NULL; pptr=pptr->back)
                        {
                            // cout << "2.0  " << pptr->num << endl;
                            pptr->reverse = true;
                        }
                        chain[n]->next = rptr;
                    }
                    else
                    {
                        // cout << "2.1  " << pptr->num << endl;
                        pptr->reverse = false;
                    }
                }
                else
                {
                    for (pptr=chain[n]; pptr!=NULL; pptr=pptr->next)
                    {
                        // cout << "2.2  " << pptr->num << endl;
                        pptr->reverse = false;
                    }
                    chain[n]->back = rptr;
                }
                rptr->next = chain[n];
                
                go_forward();
                break;
        }

        for (j=0; j<last;)
        {
            for (pptr=chain[j]; pptr!=NULL; j++)
            {
                cout << pptr->num+1 << " ";
                if (pptr->reverse)
                {
                    pptr = pptr->back;
                }
                else
                {
                    pptr = pptr->next;
                }
            }
            cout << endl;
        }

        path[i] = rptr->num;
        cout << path[i]+1 << endl;
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