#include <iostream>

using namespace std;


const int MAX_N = 3001;
short int *s = new short int[MAX_N];
short int *r = new short int[MAX_N];
short int **A = new short int*[MAX_N];
short int n;

void get_input();
void init();
short int max_a(short int i, short int j);
short int max_three(short int a, short int b, short int c);

int main()
{
    get_input();

    max_a(n, n);

    cout << A[n][n] << '\n';

    return 0;
}

void get_input()
{
    short int i;

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
    short int i, j;

    for (i=0; i<MAX_N; i++)
    {
        s[i] = 0;
        r[i] = 0;
        A[i] = new short int[MAX_N];
        for (j=0; j<MAX_N; j++)
        {
            A[i][j] = -1;
        }
    }
}

short int max_a(short int i, short int j)
{
    short int cut_l;
    short int cut_r;
    short int cut_lr;

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

short int max_three(short int a, short int b, short int c)
{
    return a>b ? a>c ? a : c : b>c ? b : c;
}
