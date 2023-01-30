#include <iostream>

using namespace std;

const int MAX_N = 100001;
int line[MAX_N];
int line_diff[MAX_N];

int abs_minus(int x, int y);

int main(void)
{
    int n, i, j, k;
    int diff, old_diff;
    int sum = 0;
    int test_sum;
    int now;
    int min = 0xfffffff;

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> line[i];
    }

    for (i=0; i<n-1; i++)
    {
        sum += abs_minus(line[i], line[i+1]);
    }
    test_sum = sum;

    // cout << test_sum;

    for (i=0; i<n; i++, old_diff=0)
    {
        // เปลี่ยนตัวที่จะหาแทน
        now = line[i];
        if (i != 0)
        {
            old_diff += abs_minus(line[i], line[i-1]);
        }
        if (i != n-1)
        {
            old_diff += abs_minus(line[i], line[i+1]);
        }
        for (j=0; j<n-1; j++, diff=0)
        {
            // ทดลองแทนด้วยตัวอื่น 
            if (j>=i-1 && j<=i+1)
            {
                continue;
            }

            // cout << i << ' ' << j << "------ ";

            line[i] = line[j];
            if (i != 0)
            {
                diff += abs_minus(line[i], line[i-1]);
            }
            if (i != n-1)
            {
                diff += abs_minus(line[i], line[i+1]);
            }
            sum = test_sum + diff - old_diff;
            if (sum < min)
            {
                min = sum;
            }
            // if (i==2 && j==0)
            // {
            //     cout << sum << " : ";
            //     for (k=0; k<n; k++)
            //     {
            //         cout << line[k] << " ";
            //     }
            //     cout << '\n';
            //     cout << old_diff << ' ' << diff << endl;
            // }
            // cout << sum << " : ";
            // for (k=0; k<n; k++)
            // {
            //     cout << line[k] << " ";
            // }
            // cout << " -------- " << diff << ' ' << old_diff;
            // cout << '\n';
        }
        line[i] = now;
        sum = test_sum;
    }

    // for (i=1; i<n; i++)
    // {
    //     sum += line_diff[i];
    // }

    cout << min << '\n';

    return 0;
}

int abs_minus(int x, int y)
{
    return x-y>0 ? x-y: y-x;
}