#include <iostream>

using namespace std;

int main(void)
{
    int n, i, kilo, count, max=0;
    int** bridge;
    double heading;

    cin >> kilo >> n;
    bridge = (int**)malloc(sizeof(int*)*n);
    for (i=0; i<n; i++)
    {
        bridge[i] = (int*)malloc(sizeof(int)*2);
        cin >> bridge[i][0] >> bridge[i][1];
    }
    for (heading=1; heading<=kilo; heading+=0.5)
    {
        for (count=0, i=0; i<n; i++)
        {
            if ((bridge[i][0]<heading) && (heading<bridge[i][1]))
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
        }
    }

    cout << max << '\n';

    return 0;
}