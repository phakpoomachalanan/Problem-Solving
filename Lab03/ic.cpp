#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int  n;
    int  temp;
    string command;
    list<int> data;
    list<int>::iterator it;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> command >> temp;

        if (command == "li")
        {

        }
        else if (command == "lr")
        {

        }
        
    }
    for (it=data.begin(); it!=data.end(); it++)
    {
        cout << *it << '\n';
    }

    return 0;
}