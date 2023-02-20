#include <iostream>

using namespace std;

const int MAX_N = 100001;
int line[MAX_N];

int abs_minus(int x, int y);

int main(void)
{
    int l, m, r;
    int n, i, h;
    int min = 0;
    int diff, temp;
    int max_diff = 0;
    int max_index = -1;
    bool is_changed = false;

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> h;
        // min += h;
        line[i] = h;
    }
    
    for (i=1; i<n-1; i++)
    {
        l = line[i-1];
        m = line[i];
        r = line[i+1];
        if (m>l && m>r)
        {
            diff = abs_minus(m, l) + abs_minus(m, r);
            if (diff > max_diff)
            {
                max_diff = diff;
                max_index = i;
            }
        }
    }
    if (max_index != -1)
    {
        l = line[max_index-1];
        r = line[max_index+1];
        for (i=0; i<n; i++)
        {
            if (i<=max_index+1 && i>=max_index-1)
            {
                continue;
            }
            m = line[i];
            if ((m>l && m<r) || (m>r && m<l))
            {
                line[max_index] = m;
                is_changed = true;
                break;
            }
        }
    }
    if (!is_changed)
    {
        l = line[max_index-1];
        r = line[max_index+1];
        for (i=0; i<n; i++)
        {
            if (i<=max_index+1 && i>=max_index-1)
            {
                continue;
            }
            m = line[i];
            diff = abs_minus(m, l) + abs_minus(m, r);
            if (diff < max_diff)
            {
                line[max_index] = m;
                max_diff = diff;
            }
        }
    }
    for (i=1; i<n; i++)
    {
        min += abs_minus(line[i], line[i-1]);
    }

    cout << min << '\n';

    return 0;
}

int abs_minus(int x, int y)
{
    return x-y>0 ? x-y: y-x;
}