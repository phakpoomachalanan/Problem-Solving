#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int  n;
    int  temp;
    char command;
    list<int> data;
    list<int>::iterator it;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> command >> temp;

        switch (command)
        {
            case 'I':
                data.push_front(temp);
                break;

            case 'A':
                data.push_back(temp);
                break;

            case 'D':
                if (temp <= data.size())
                {
                    it = data.begin();
                    advance(it, temp-1);
                    data.erase(it);
                }
                break;
        }
    }
    for (it=data.begin(); it!=data.end(); it++)
    {
        cout << *it << '\n';
    }

    return 0;
}