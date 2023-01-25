#include <iostream>

using namespace std;

int  n;
bool can;
const int MAX_N = 21;
char map[MAX_N][MAX_N] = {'\0'};
bool visited[MAX_N][MAX_N] = {false};
int des_y, des_x;

void init();
void find_exit(int y, int x, bool key_used);

int main(void)
{
    int i, j, ask;
    int sta_y, sta_x;

    cin >> n >> ask;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (i=0; i<ask; i++)
    {
        cin >> sta_y >> sta_x >> des_y >> des_x;
        des_y--; des_x--;
        init();
        find_exit(sta_y-1, sta_x-1, false);

        if (can)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}

void init()
{
    int i, j;

    can = false;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            visited[i][j] = false;
        }
    }

    return;
}

void find_exit(int y, int x, bool key_used)
{
    if (y>n-1 || y<0 || x>n-1 || x<0)
    {
        return;
    }
    if (map[y][x]=='#' || visited[y][x])
    {
        return;
    }
    if (map[y][x] == 'O')
    {
        if (key_used)
        {
            return;
        }
        else
        {
            key_used = true;
        }
    }
    if (y==des_y && x==des_x)
    {
        can = true;
        return;
    }

    visited[y][x] = true;

    find_exit(y+1, x, key_used);
    find_exit(y-1, x, key_used);
    find_exit(y, x+1, key_used);
    find_exit(y, x-1, key_used);

    return;
}