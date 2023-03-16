#include <iostream>

using namespace std;

const int MAX_N = 3001;
int s[MAX_N];
int r[MAX_N];
int A[MAX_N][MAX_N];
int n;

void get_input();
void init();
int max_a(int i, int j);
int max_three(int a, int b, int c);

int main()
{
    get_input();

    max_a(n, n);

    cout << A[n][n] << '\n';

    return 0;
}

void get_input()
{
    int i;

    cin >> n;

    init();

    for (i=0; i<n; i++)
    {
        cin >> s[i];
    }
    for (i=0; i<n; i++)
    {
        cin >> r[i];
    }

    return;
}

void init()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        s[i] = 0;
        r[i] = 0;
        for (j=0; j<n; j++)
        {
            A[i][j] = -1;
        }
    }
}

int max_a(int i, int j)
{
    int cut_l;
    int cut_r;
    int cut_lr;

    if (i<=0 || j<=0)
    {
        return 0;
    }
    if (A[i][j] != -1)
    {
        return A[i][j];
    }

    cut_l = A[i-1][j]==-1 ? max_a(i-1, j) : A[i-1][j];
    cut_r = A[i][j-1]==-1 ? max_a(i, j-1) : A[i][j-1];

    if (s[i-1] == r[j-1])
    {
        cut_lr = A[i-1][j-1]==-1 ? 1+max_a(i-1, j-1) : 1+A[i-1][j-1];
    }
    else
    {
        cut_lr = 0;
    }

    A[i][j] = max_three(cut_l, cut_r, cut_lr);

    return A[i][j];
}

int max_three(int a, int b, int c)
{
    return a>b ? a>c ? a : c : b>c ? b : c;
}