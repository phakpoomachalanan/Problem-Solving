#include <iostream>
#include <list>

using namespace std;

typedef struct pepo
{
    int index;
    int perfomance;
}
pepo_t;

int main(void)
{
    int n, i, j, temp;
    int max=0, third, fourth;
    pepo_t top[4];
    pepo_t first, second;

    for (i=0; i<4; i++)
    {
        top[i].perfomance = 0;
    }

    cin >> n;

    for (i=0; i<4; i++)
    {
        for (j=1; j<=n; j++)
        {
            cin >> temp;
            if (temp > top[i].perfomance)
            {
                top[i].perfomance = temp;
                top[i].index = i*n + j;
            }
        }
    }

    if (top[0].perfomance > top[1].perfomance)
    {
        first = top[0];
        third = top[1].index;
    }
    else
    {
        first = top[1];
        third = top[0].index;
    }
    if (top[2].perfomance > top[3].perfomance)
    {
        second = top[2];
        fourth = top[3].index;
    }
    else
    {
        second = top[3];
        fourth = top[2].index;
    }
    if (first.perfomance > second.perfomance)
    {
        cout << first.index << '\n' << second.index << '\n';
    }
    else
    {
        cout << second.index << '\n' << first.index << '\n';
    }
    cout << third << '\n' << fourth << '\n';

    
    return 0;
}