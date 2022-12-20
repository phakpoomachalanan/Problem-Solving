#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int n, i, head, tail, j;
    int head_line, tail_line;
    list<int> lace[300001];
    list<int>::iterator itr, head_itr, tail_itr;

    cin >> n;
    //lace = (list<int>*)malloc(sizeof(list<int>)*n);

    for (i=0; i<n; i++)
    {
        lace[i].push_back(i+1);
    }
    for (i=0; i<n-1; i++)
    {
        cin >> head, tail;
        for (j=0; j<n; j++)
        {
            for (itr=lace[j].begin(); itr!=lace[j].end(); itr++)
            {
                if (*itr == tail)
                {
                    tail_itr = itr;
                    break;
                }
            }
            if (tail_itr != lace[j].end())
            {
                tail_line = j;
                break;
            }
        }
        for (j=0; j<n; j++)
        {
            for (itr=lace[j].begin(); itr!=lace[j].end(); itr++)
            {
                if (*itr == head)
                {
                    head_itr = itr;
                    break;
                }
            }
            if (head_itr != lace[j].end())
            {
                head_line = j;
                break;
            }
        }
        lace[tail_line].splice(tail_itr, lace[head_line]);
    }
    for (i=0; i<n-1; i++)
    {
        if (lace[i].size() != 0)
        {
            for (itr=lace[i].begin(); itr!=lace[i].end(); itr++)
            {
                cout << *itr << ' ';
            }
        }
    }
    cout << '\n';

    return 0;
}