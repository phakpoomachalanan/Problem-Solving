#include <iostream>
#include <list>
#include <stack>

using namespace std;

int main(void)
{
    int  mode = 0;
    char ch;
    list<char> temp;
    list<char> text;
    list<char>::iterator itr;

    do
    {
        ch = getchar();
        if (ch == '[')
        {
            mode = 1;
        }
        else if (ch == ']')
        {
            mode = 0;
            text.splice(text.begin(), temp);
        }
        else if (ch == '\n')
        {
            mode = 0;
            text.splice(text.begin(), temp);
            text.push_back('\n');
        }
        else if (mode == 0)
        {
            text.push_back(ch);
        }
        else if (mode == 1)
        {
            temp.push_back(ch);
        }
    }
    while (ch != EOF);
    text.splice(text.begin(), temp);
    text.push_back('\0');

    for (itr=text.begin(); itr!=text.end(); itr++)
    {
        cout << *itr;
    }
    cout << '\n';

    return 0;
}