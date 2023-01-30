#include <iostream>

using namespace std;

const int MAX_N = 100001;
int line[MAX_N];
int line_diff[MAX_N];

int main(void)
{
    int n, i, j, k;
    int diff;
    int sum = 0;
    int now;
    int min = 0xfffffff;

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> line[i];
    }

    for (i=1; i<n; i++)
    {
        sum += line[i] - line[i-1];
    }

    for (i=0; i<n; i++)
    {
        // เปลี่ยนตัวที่จะหาแทน
        now = line[i];
        for (j=0; j<n-1; j++)
        {
            // ทดลองแทนด้วยตัวอื่น 
            if (j>=i-1 && j<=i+1)
            {
                continue;
            }

            // cout << i << ' ' << j << "------ ";
            sum = 0;
            line[i] = line[j];
            for (k=0; k<n-1; k++)
            {
                diff = line[k] - line[k+1];
                sum += diff>0 ? diff : diff*-1;
            }
            if (sum < min)
            {
                min = sum;
            }
            // cout << sum << " : ";
            // for (k=0; k<n; k++)
            // {
            //     cout << line[k] << " ";
            // }
            // cout << '\n';
        }
        line[i] = now;
    }

    // for (i=1; i<n; i++)
    // {
    //     sum += line_diff[i];
    // }

    cout << min << '\n';

    return 0;
}