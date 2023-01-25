#include <iostream>

using namespace std;

int main(void)
{
    int deal[101][3];
    int weight[1001];
    int n, k, i, j;
    int min = 0xfffffff;
    int temp, cost;

    cin >> k >> n;

    for (i=0; i<k; i++)
    {
        for (j=0; j<3; j++)
        {
            cin >> deal[i][j];
        }
    }
    for (i=0; i<n; i++)
    {
        cin >> weight[i];
    }
    for (i=0; i<k; i++)
    {
        temp = 0;
        cost = deal[i][0] + deal[i][1];

        for(j=0; j<n; j++)
        {
            temp += weight[j];
            if (weight[j] > deal[i][2])
            {
                cost = 0;
                break;
            }
            if (temp > deal[i][2])
            {
                temp = weight[j];
                cost += deal[i][1];
            }
        }
        if (cost < min && cost > 0)
        {
            min = cost;
        }
    }

    cout << min << '\n';

    return 0;
}