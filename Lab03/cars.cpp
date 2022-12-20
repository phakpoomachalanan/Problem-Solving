#include <iostream>

using namespace std;

int main(void)
{
    int  n, count=0, i;
    int  temp, max;
    int* row;

    cin >> n;
    row = (int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++)
    {
        cin >> temp >> row[i];
    }
    max = row[n-1];
    for (i=n-1; i>=0; i--)
    {
        if (max < row[i])
        {
            max = row[i];
        }
        if (max > row[i])
        {
            count++;
        }
    }
    cout << count << '\n';

    return 0;
}