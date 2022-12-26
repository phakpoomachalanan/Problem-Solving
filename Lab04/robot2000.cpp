#include <iostream>

using namespace std;

int main(void)
{
    int  i, j, pstate=0, nstate=0;
    int  diff;
    char ch;
    string converted;
    string command;

    getline(cin, command);

    for (i=0; i<command.size(); i++)
    {
        ch = command[i];
        if (ch == 'Z')
        {
            pstate = 0;
            converted.push_back('Z');
            continue;
        }
        else if (ch == 'N')
        {
            nstate = 0;
        }
        else if (ch == 'E')
        {
            nstate = 1;
        }
        else if (ch == 'S')
        {
            nstate = 2;
        }
        else if (ch == 'W')
        {
            nstate = 3;
        }
        diff = nstate >= pstate ? nstate-pstate : 4-(pstate-nstate)%4;
        for (j=0; j<diff; j++)
        {
            converted.push_back('R');
        }
        converted.push_back('F');
        pstate = nstate;
    }
    cout << converted << '\n';

    return 0;
}