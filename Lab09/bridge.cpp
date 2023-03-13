#include <iostream>

using namespace std;

const int MAX_N = 3001;
int l_bridge[MAX_N];
int r_bridge[MAX_N];
int a[MAX_N][MAX_N];
int n;

void get_input();
void init();
int max_a(int i, int j);
int max(int a, int b, int c);

int main()
{
    get_input();

    max_a(n-1, n-1);

    // cout << a[n-1][n-1] << '\n';
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void get_input()
{
    int i;

    cin >> n;

    init();
    for (i=0; i<n; i++)
    {
        cin >> l_bridge[i];
    }
    for (i=0; i<n; i++)
    {
        cin >> r_bridge[i];
    }
}

void init()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        l_bridge[i] = 0;
        r_bridge[i] = 0;

        for (j=0; j<n; j++)
        {
            a[i][j] = -1;
        }
    }
}

int max_a(int i, int j)
{
    int cut_l;
    int cut_r;
    int cut_lr;


    if (i<0 || j<0)
    {
        return 0;
    }
    if (a[i][j] != -1)
    {
        return a[i][j];
    }
    // if (a[i-1][j] == -1)
    // {
    //     cut_l = max_a(i-1, j);
    // }
    // else
    // {
    //     cut_l = a[i-1][j];
    // }
    // if (a[i][j-1] == -1)
    // {
    //     cut_r = max_a(i, j-1);
    // }
    // else
    // {
    //     cut_r = a[i][j-1];
    // }

    cut_l = a[i-1][j]==-1 ? max_a(i-1, j) : a[i-1][j];
    cut_r = a[i][j-1]==-1 ? max_a(i, j-1) : a[i][j-1];

    if (l_bridge[i] == r_bridge[j])
    {
        cut_lr = a[i-1][j-1]==-1 ? 1+max_a(i-1, j-1) : 1+a[i-1][j-1];
        // if (a[i-1][j-1] == -1)
        // {
        //     cut_lr = 1 + max_a(i-1, j-1);
        // }
        // else
        // {
        //     cut_lr = 1 + a[i-1][j-1];
        // }
    }
    else
    {
        cut_lr = 0;
    }

    cout << i << " " << j << endl;
    cout << cut_l << " " << cut_r << " " << cut_lr << endl;

    a[i][j] = max(cut_l, cut_r, cut_lr);

    return a[i][j];
}

int max(int a, int b, int c)
{
    // if (a>b && a>c)
    // {
    //     return a;
    // }
    // if (b>a && b>c)
    // {
    //     return b;
    // }
    // return c;

    return a>b ? a>c ? a : c : b>c ? b : c;
}