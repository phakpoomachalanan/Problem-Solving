#include <iostream>

using namespace std;

const int MAX_N = 3001;
int l_bridge[MAX_N];
int r_bridge[MAX_N];
int n;

void get_input();
void init();

int main()
{
    get_input();

    return 0;
}

void get_input()
{
    int i, j;

    cin >> n;

    for (i=0; i<n; i++)
    {
        cin >> l_bridge[i];
    }
    for (i=0; i<n; i++)
    {
        cin >> r_bridge[i];
    }
}

void init()
{
    int i;

    for (i=0; i<n; i++)
    {
        l_bridge[i] = 0;
        r_bridge[i] = 0;
    }
}