#include <iostream>

using namespace std;

const int MAX_N = 21;

int n, m;
int table[MAX_N][MAX_N];
int output, num;

void get_input();
void compare();
int check_left(int y, int x);
int check_right(int y, int x);
int check_up(int y, int x);
int check_down(int y, int x);
int abs(int a);

int main()
{
    get_input();
    compare();

    cout << output << '\n';

    return 0;
}

void get_input()
{
    int i, j;

    cin >> n >> m;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> table[i][j];
        }
    }

    return;
}

void compare()
{
    int lowest_cost = 0xfffffff;
    int sum;
    int i, j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            num = 0;
            sum = check_left(i, j) + check_right(i, j) + check_up(i, j) + check_down(i, j);
            sum /= (num-4);
            if (sum < lowest_cost)
            {
                lowest_cost = sum;
                output = table[i][j];
            }
        }
    }

    return;
}

int check_left(int y, int x)
{
    int i, piece = 0;
    int minus = table[y][x];

    for (i=x; i>=0; i--)
    {
        piece += abs(minus - table[y][i]);
        num++;
    }

    return piece;
}

int check_right(int y, int x)
{
    int i, piece = 0;
    int minus = table[y][x];

    for (i=x; i<m; i++)
    {
        piece += abs(minus - table[y][i]);
        num++;
    }

    return piece;
}

int check_up(int y, int x)
{
    int i, piece = 0;
    int minus = table[y][x];

    for (i=y; i>=0; i--)
    {
        piece += abs(minus - table[i][x]);
        num++;
    }

    return piece;
}

int check_down(int y, int x)
{
    int i, piece = 0;
    int minus = table[y][x];

    for (i=y; i<n; i++)
    {
        piece += abs(minus - table[i][x]);
        num++;
    }

    return piece;
}

int abs(int a)
{
    return a>0 ? a : -1*a;
}