#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int  mode = 0;
    int  flag;
    char ch;
    list<char> temp;
    list<char> text;
    list<char>::iterator itr;

    while ((ch=getchar()) != EOF)
    {
        flag = 0;
        if (mode == 0 && ch == '[')
        {
            mode = 1;
        }
        else if (mode == 1 && ch == '[')
        {
            text.splice(text.begin(), temp);
            temp.clear();
        }
        else if (ch == ']')
        {
            mode = 0;
            text.splice(text.begin(), temp);
            temp.clear();
        }
        else if (ch == '\n')
        {
            mode = 0;
            text.splice(text.begin(), temp);
            text.push_back('\n');
            for (itr=text.begin(); itr!=text.end(); itr++)
            {
                cout << *itr;
            }
            text.clear();
            temp.clear();
            flag = 1;
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
    text.splice(text.begin(), temp);

    for (itr=text.begin(); itr!=text.end(); itr++)
    {
        cout << *itr;
    }
    if (flag == 0)
    {
        cout << '\n';
    }

    return 0;
}