#include <iostream>

using namespace std;

int main(void)
{
    int    N=0, E=0, S=0, W=0;
    int    i, lost, max_energy=0, counter_dir=0;
    char   ch;
    string command;

    getline(cin, command);
    cin >> lost;

    for (i=0; i<command.size(); i++)
    {
        ch = command[i];
        switch (ch)
        {
            case 'N':
                N++;
                break;
            case 'E':
                E++;
                break;
            case 'S':
                S++;
                break;
            case 'W':
                W++;
                break;
        }
    }
    
    if (N > S)
    {
        max_energy += N;
        counter_dir += S;
    }
    else
    {
        max_energy += S;
        counter_dir += N;
    }
    if (E > W)
    {
        max_energy += E;
        counter_dir += W;
    }
    else
    {
        max_energy += W;
        counter_dir += E;
    }
    counter_dir = counter_dir > lost ? counter_dir-lost : lost-counter_dir;

    cout << (max_energy-counter_dir)*2 << '\n';

    return 0;
}