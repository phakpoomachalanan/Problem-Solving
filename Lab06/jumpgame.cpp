#include <iostream>
#include <vector>

using namespace std;

int  n, jump;
bool can;
const int MAX_N = 21;
int map[MAX_N][MAX_N] = {0};
bool visited[MAX_N][MAX_N] = {false};

void find_exit(int y, int x, int last_top);

int main(void)
{
    int i, j;
    int top;

    cin >> n >> jump;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> top;
            map[i][j] = top;
        }
    }

    find_exit(0, 0, map[0][0]);

    if (can)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }

    return 0;
}

void find_exit(int y, int x, int last_top)
{
    if (y>n-1 || y<0 || x>n-1 || x<0)
    {
        return;
    }
    if (visited[y][x])
    {
        return;
    }
    if (last_top < map[y][x]-jump)
    {
        return;
    }
    if (y==n-1 && x==n-1)
    {
        can = true;
        return;
    }

    visited[y][x] = true;

    find_exit(y+1, x, map[y][x]);
    find_exit(y-1, x, map[y][x]);
    find_exit(y, x+1, map[y][x]);
    find_exit(y, x-1, map[y][x]);

    return;
}