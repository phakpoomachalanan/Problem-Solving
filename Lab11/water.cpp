#include <iostream>

using namespace std;

const int MAX_N = 1001;

int n;
int level[MAX_N];
int output = 0;

void get_input();
void cal();

int main()
{
    get_input();
    cal();

    cout << output << '\n';

    return 0;
}

void get_input()
{
    int i;

    cin >> n;

    for (i=0; i<n; i++)
    {
        cin >> level[i];
    }

    return;
}

void cal()
{
    int i;
    int power;

    for (i=1; i<n; i++)
    {
        if (level[i-1] > level[i]+10)
        {
            power = (level[i-1]-level[i])*10;
            output += power>700? 700 : power;
        }
    }

    return;
}