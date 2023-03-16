#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 401;

int a[MAX_N][MAX_N];
int len_y, len_x;
string y, x;

void get_input();
void init();
int min_three(int a, int b, int c);

int main()
{
    int i, j;

    get_input();

    for (i=1; i<=len_y; i++)
    {
        for (j=1; j<=len_x; j++)
        {
            if (y[i-1] == x[j-1])
            {
                a[i][j] = a[i-1][j-1];
            }
            else
            {
                a[i][j] = 1 + min_three(a[i-1][j], a[i][j-1], a[i-1][j-1]);
            }
        }
    }

    cout << a[len_y][len_x] << '\n';

    return 0;
}

void get_input()
{
    getline(cin, y);
    getline(cin, x);

    len_y = y.length();
    len_x = x.length();

    init();

    return;
}

void init()
{
    int i;

    for (i=0; i<=len_y; i++)
    {
        a[i][0] = i;
    }
    for (i=0; i<=len_x; i++)
    {
        a[0][i] = i;
    }

    return;
}

int min_three(int a, int b, int c)
{
    return a<b ? (a<c ? a : c) : (b<c ? b : c);
}