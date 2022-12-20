#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int  n, k, j;
    char command;
    list<int>::iterator it;
    list<int> data[100000];

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> command >> k >> j;
        switch (command)
        {
            case 'N':
                data[j].push_back(k);
                break;

            case 'M':
                data[j].splice(data[j].end(), data[k]);
                break;
        }
    }
    for (int i=0; i<n; i++)
    {
        for (it=data[i].begin(); it!=data[i].end(); it++)
        {
            if (*it != 0)
            {
                cout << *it << '\n';
            }
        }
    }

    return 0;
}