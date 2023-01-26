#include <iostream>

using namespace std;

int  destination;
bool can;
const int MAX_N = 21;
bool visited[MAX_N][MAX_N] = {false};

void init();
void find_exit(int y, int x, bool tollway_used);

int main(void)
{
    int i, j, route;
    int sta_y, sta_x;

    cin >> destination >> route;

    for (i=0; i<route; i++)
    {
        
    }

    init();
    find_exit(sta_y-1, sta_x-1, false);

    if (can)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

void init()
{
    int i, j;

    can = false;
    for (i=0; i<destination; i++)
    {
        for (j=0; j<destination; j++)
        {
            visited[i][j] = false;
        }
    }

    return;
}

void find_exit(int y, int x, bool tollway_used)
{
    if (0 || visited[y][x])
    {
        return;
    }
    if (1)
    {
        if (tollway_used)
        {
            return;
        }
        else
        {
            tollway_used = true;
        }
    }

    visited[y][x] = true;

    find_exit(y+1, x, tollway_used);
    find_exit(y-1, x, tollway_used);
    find_exit(y, x+1, tollway_used);
    find_exit(y, x-1, tollway_used);

    return;
}