#include <iostream>
#include <vector>

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
    int  n, m, times;
    int  i, j, k, last=1;
    int type, flag;
    int* path;
    char command;
    list_t* next_position;
    list_t* robot_ptr;
    list_t* list_temp;
    list_t* last_ptr;
    list_t* ptr;
    list_t* chain;
    vector<list_t*> head;
    vector<list_t*> tail;
    vector<list_t*>::iterator itr;

    cin >> n >> times;
    path = new int[n];

    for (i=0; i<n; i++)
    {
        cin >> m;

        last_ptr = NULL;
        list_temp = new list_t;
        ptr = list_temp;
        for (j=last; j<last+m; j++)
        {
            ptr->back = last_ptr;
            ptr->num = j;
            last_ptr = ptr;
            ptr->next = new list_t;
            ptr = ptr->next;
        }
        free(last_ptr->next);
        last_ptr->next = NULL;
        head.push_back(list_temp);
        tail.push_back(last_ptr);
        last += m;
    }

    chain = head[0];
    robot_ptr = chain;
    head.erase(head.begin());
    tail.erase(tail.begin());

    for (i=0; i<times; i++)
    {
        cin >> command;

        switch(command)
        {
            case 'F':
                if (robot_ptr->next != NULL)
                {
                    robot_ptr = robot_ptr->next;
                }
                break;
            case 'B':
                if (robot_ptr->back != NULL)
                {
                    robot_ptr = robot_ptr->back;
                }
                break;
            case 'C':
                cin >> m;

                next_position = robot_ptr->next;
                if (next_position != NULL)
                {
                    head.push_back(next_position);
                    next_position->back = NULL;
                    for (ptr=next_position; ptr->next!=NULL; ptr=ptr->next) {}
                    tail.push_back(ptr);
                    ptr->next = NULL;
                }
                robot_ptr->next = NULL;

                flag = 0;

                for (j=0; j<head.size(); j++)
                {
                    if (head[j]->num == m)
                    {
                        flag = 1;
                        k = j;
                        break;
                    }
                    else if (tail[j]->num == m)
                    {
                        flag = 2;
                        k = j;
                        break;
                    }
                }

                if (flag == 1)
                {
                    robot_ptr->next = head[k];
                    head[k]->back = robot_ptr;
                }
                else if (flag == 2)
                {
                    for (ptr=tail[k]; ptr!=NULL; ptr=ptr->next)
                    {
                        last_ptr = ptr->back;
                        ptr->back = ptr->next;
                        ptr->next = last_ptr;
                    }
                    robot_ptr->next = tail[k];
                    tail[k]->back = robot_ptr;
                }
                itr = head.begin();
                advance(itr, j);
                head.erase(itr);
                itr = tail.begin();
                advance(itr, j);
                tail.erase(itr);
        
                robot_ptr = robot_ptr->next;
                break;
        }
        path[i] = robot_ptr->num;
        cout << path[i] << "\n";
    }

    for (i=0; i<times; i++)
    {
        cout << path[i] << '\n';
    }

    return 0;
}