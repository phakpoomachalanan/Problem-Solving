#include <iostream>

using namespace std;

int main(void)
{
    int i;
    int count=0, order=0;
    string text, name;

    cin >> name;
    cin >> text;

    for (i=0; i<text.size(); i++)
    {
        if (text[i] == name[order])
        {
            order++;
        }
        if (order == name.size())
        {
            order = 0;
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}