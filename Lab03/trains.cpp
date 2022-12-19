#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int  n, i, j;
    char command;
    list<int>::iterator it;
    //list<list<int>> data;
    //list<list<int>>::iterator itit;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> command >> i >> j;
        switch (command)
        {
            case 'N':
                break;

            case 'M':
                break;
        }
    }
}