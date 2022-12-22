#include <iostream>

using namespace std;

typedef struct node
{
    int left;
    int num;
    struct node* next;
}
list_t;

int main(void)
{
    int n, i, j;
    int head, tail;
    list_t*  ptr;
    list_t** lace;

    cin >> n;
    lace = (list_t**)malloc(sizeof(list_t*)*n);
    for (i=0; i<=n; i++)
    {
        lace[i] = (list_t*)malloc(sizeof(list_t));
        lace[i]->left = i;
        lace[i]->num = i;
        lace[i]->next = NULL;
    }

    for (i=0; i<n-1; i++)
    {
        cin >> head >> tail;
        lace[head]->left = tail;

        for (ptr=lace[head]; ptr->next!=NULL; ptr=ptr->next) {}
        ptr->next = lace[tail]->next;
        lace[tail]->next = lace[head];
    }
    for (i=1; i<=n; i++)
    {
        if (lace[i]->left == lace[i]->num)
        {
            ptr = lace[i];
            break;
        }
    }
    for (;ptr!=NULL; ptr=ptr->next)
    {
        cout << ptr->num << ' ';
    }
    cout << '\n';

    return 0;
}