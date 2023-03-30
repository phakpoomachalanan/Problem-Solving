#include <iostream>

using namespace std;

const int MAX_N = 31;

int n, m;
int table[MAX_N][MAX_N];
int fewest_piece[MAX_N][MAX_N];

void get_input();
void compare();
int min(int a, int b);
void print_output();
int check_left(int y, int x);
int check_right(int y, int x);
int check_up(int y, int x);
int check_down(int y, int x);

int main()
{
    get_input();
    compare();
    print_output();

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
    int i, j;
    int left, right, up, down;
    int compare_i, compare_j;
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            left = check_left(i, j);
            right = check_right(i, j);
            up = check_up(i, j);
            down = check_down(i, j); 

            compare_i = min(left, right);
            compare_j = min(up, down);

            fewest_piece[i][j] = min(compare_i, compare_j);
        }
    }
}

int min(int a, int b)
{
    return a>b ? b : a;
}

void print_output()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cout << fewest_piece[i][j] << " ";
        }
        cout << '\n';
    }

    return;
}

int check_left(int y, int x)
{
    int i, piece = 0;

    for (i=x; i>=0; i--)
    {
        piece += table[y][i];
    }

    return piece;
}

int check_right(int y, int x)
{
    int i, piece = 0;

    for (i=x; i<m; i++)
    {
        piece += table[y][i];
    }

    return piece;
}

int check_up(int y, int x)
{
    int i, piece = 0;

    for (i=y; i>=0; i--)
    {
        piece += table[i][x];
    }

    return piece;
}

int check_down(int y, int x)
{
    int i, piece = 0;

    for (i=y; i<n; i++)
    {
        piece += table[i][x];
    }

    return piece;
}