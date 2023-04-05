#include <iostream>

using namespace std;

const int MAX_N = 21;

int n;
char box[MAX_N][MAX_N];

void get_input();
void pre_traversal();
void traversal(int y, int x, int dir);
int exit_num(int y, int x);

int main()
{
    get_input();
    pre_traversal();

    return 0;
}

void get_input()
{
    int i, j;

    cin >> n;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> box[i][j];
        }
    }

    return;
}

void pre_traversal()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        traversal(i, 0, 4);
    }
    for (i=0; i<n; i++)
    {
        traversal(n-1, i, 1);
    }
    for (i=0; i<n; i++)
    {
        traversal(n-1-i, n-1, 2);
    }
    for (i=0; i<n; i++)
    {
        traversal(0, n-1-i, 3);
    }

    return;
}

void traversal(int y, int x, int dir)
{
    char item;
    // dir value
    //   1
    // 2   4
    //   3
    if (x>n-1 || x<0 || y>n-1 || y<0)
    {
        cout << exit_num(y, x) << '\n';
        return;
    }

    item = box[y][x];
    
    if (item == '.')
    {
        if (dir%2)
        {
            traversal(y+dir-2, x, dir);
        }
        else
        {
            traversal(y, x+dir-3, dir);
        }
    }
    else if (item == '/')
    {
        if (dir%2)
        {
            traversal(y, x-dir+2, dir==1?4:2);
        }
        else
        {
            traversal(y-dir+3, x, dir==4?1:3);
        }
    }
    else if (item == '\\')
    {
        if (dir%2)
        {
            traversal(y, x+dir-2, dir+1);
        }
        else
        {
            traversal(y+dir-3, x, dir-1);
        }
    }

    return;
}

int exit_num(int y, int x)
{
    if (x == n)
    {
        return 3*n - y;
    }
    if (y == n)
    {
        return n + x + 1;
    }
    if (x == -1)
    {
        return y + 1;
    }
    if (y == -1)
    {
        return 4*n - x;
    }

    return -1;
}