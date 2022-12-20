#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int temp;
    list<int> deck, sand;
    list<int>::iterator it, itr;

    cin >> temp;
    do
    {
        deck.push_back(temp);
        cin >> temp;
    }
    while (temp != 0);

    for (it=deck.begin(); it!=deck.end(); it++)
    {
        sand.clear();
        for (int i=0; i<*it; i++)
        {
            sand.push_back(i+1);
        }
        cout << "Discarded cards:";
        while (sand.size() != 1)
        {
            itr = sand.begin();
            cout << ' ' << *itr;
            if (sand.size() > 2)
            {
                cout << ',';
            }
            sand.erase(itr);
            itr = sand.begin();
            sand.push_back(*itr);
            sand.erase(itr);
        }
        cout << "\nRemaining card: " << *sand.begin() << '\n';
    }

    return 0;
}