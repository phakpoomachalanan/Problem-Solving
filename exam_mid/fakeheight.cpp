#include <iostream>

using namespace std;

const int MAX_N = 100001;
int line[MAX_N];

int abs_minus(int x, int y);

int main(void)
{
    int n, i, h;
    int min = 0;

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> h;
        min += h;
        line[i] = h;
    }

    cout << min << '\n';

    return 0;
}