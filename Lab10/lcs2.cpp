#include <iostream>
#include <list>

using namespace std;

const int MAX_N = 202;
string s, r;
int A[MAX_N][MAX_N];
int B[MAX_N][MAX_N];
int len_s, len_r;

void get_input();
void init();
int max_a(int i, int j);
int max_three(int a, int b, int c, int i, int j);

int main()
{
    int i, j;
    list<char> output;

    get_input();
    i = len_s;
    j = len_r;

    max_a(len_s, len_r);

    cout << A[len_s][len_r] << '\n';

    while (i>0 || j>0)
    {
        if (B[i][j] == 0)
        {
            i--;
        }
        else if (B[i][j] == 1)
        {
            j--;
        }
        else if (B[i][j] == 2)
        {
            output.push_front(s[i-1]);
            i--; j--;
        }
    }
    for (auto ch: output)
    {
        cout << ch;
    }
    cout << '\n';

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

    A[i][j] = max_three(cut_l, cut_r, cut_lr, i, j);

    return A[i][j];
}

int max_three(int a, int b, int c, int i, int j)
{
    if (a > b)
    {
        if (a > c)
        {
            B[i][j] = 0;
            return a;
        }
        else
        {
            B[i][j] = 2;
            return c;
        }
    }
    else if (b > c)
    {
        B[i][j] = 1;
        return b;
    }

    B[i][j] = 2;
    return c;
}