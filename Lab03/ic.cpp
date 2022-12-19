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
        cin >> command;

        if (command == "li")
        {
            cin >> temp;
            data.push_front(temp);
        }
        else if (command == "lr")
        {
            it = data.begin();
            temp = *it;
            data.remove(*it);
            data.push_back(temp);
        }
        else if (command == "ri")
        {
            cin >> temp;
            data.push_back(temp);
        }
        else if (command == "rr")
        {
            it = data.begin();
            advance(it , data.size()-1);
            temp = *it;
            data.remove(*it);
            data.push_front(temp);
        }
    }
    for (it=data.begin(); it!=data.end(); it++)
    {
        cout << *it << '\n';
    }

    return 0;
}