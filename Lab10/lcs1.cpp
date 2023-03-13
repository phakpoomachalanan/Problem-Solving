#include <iostream>

using namespace std;

const int MAX_N = 202;
string s, r;
int A[MAX_N][MAX_N];
int len_s, len_r;

void get_input();
void init();
int max_a(int i, int j);
int max_three(int a, int b, int c);

int main()
{
    get_input();

    max_a(len_s, len_r);

    cout << A[len_s][len_r] << '\n';

    return 0;
}

void get_input()
{
    init();

    getline(cin, s);
    getline(cin, r);

    len_s = s.length();
    len_r = r.length();

    return;
}

void init()
{
    int i, j;

    for (i=0; i<MAX_N; i++)
    {
        for (j=0; j<MAX_N; j++)
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