#include <iostream>

using namespace std;

int  n, m;
bool can;
const int MAX_N = 31;
const int MAX_M = 31;
char map[MAX_N][MAX_M] = {0};
bool visited[MAX_N][MAX_M] = {false};

void find_exit(int y, int x);

int main(void)
{
    int  i, j;

    cin >> n >> m;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (i=0; i<n; i++)
    {
        if (!visited[0][i])
        {
            find_exit(0, i);
        }
    }

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

void find_exit(int y, int x)
{
    if (y>=n-1 || y<0 || x>=m-1 || x<0)
    {
        return;
    }
    if (map[y][x] == '#' || visited[y][x])
    {
        return;
    }
    if (y == n-2 && map[y+1][x] == '.' && map[y+1][x+1] == '.' && map[y][x+1] == '.')
    {
        can = true;
        return;
    }

    visited[y][x] = true;
    
    if (map[y][x+1] == '.' && map[y+1][x] == '.' && map[y+1][x+1] == '.')
    {
        find_exit(y+1, x);
        find_exit(y-1, x);
        find_exit(y, x+1);
        find_exit(y, x-1);
    }

    return;
}