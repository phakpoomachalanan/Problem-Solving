#include <iostream>

using namespace std; 

const int MAX_N = 201;

int n;
int a[MAX_N][MAX_N];
string rna;

void get_input();
void init();
int max_a(int l, int r);

int main()
{
    int max_pair, i, j;

    get_input();

    max_a(0, n-1);

    max_pair = a[0][0];
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            max_pair = max(max_pair, a[i][j]);
        }
    }

    cout << max_pair << '\n';

    return 0;
}

void get_input()
{
    getline(cin, rna);
    n = rna.length();

    init();

    return;
}

void init()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            a[i][j] = -1;
        }
    }

    return;
}

int max_a(int l, int r)
{
    int k, max_pair = 0;
    int cut, paired;
    if (l<0 || r<0)
    {
        return 0;
    }

    if (r < l+4)
    {
        a[l][r] = 0;
        return 0;
    }

    if (a[l][r] != -1)
    {
        return a[l][r];
    }
    
    cut = max_a(l, r-1);

    for (k=l; k<r-4; k++)
    {
        if (rna[k]+rna[r]==150 || rna[k]+rna[r]==138)
        {
            paired = 1 + max_a(l, k-1) + max_a(k+1, r-1);
            max_pair = max(paired, max_pair);
        }
    }

    return a[l][r] = max(cut, max_pair);
}