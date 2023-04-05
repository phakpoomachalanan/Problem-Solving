#include <iostream>

using namespace std;

const int MAX_N = 100001;

int n, m;
int line[MAX_N];
int max_num = 0;
int max_count = 0;

void get_input();
void progess();
void keep_result(int num, int count);

int main()
{
    get_input();
    progess();

    cout << max_num << ' ' << max_count << '\n';

    return 0;
}

void get_input()
{
    int i;

    cin >> m >> n;

    for (i=0; i<n; i++)
    {
        cin >> line[i];
    }
    max_num = m + 1;

    return;
}

void progess()
{
    int i, num;
    int location = -1;
    int now_num = line[0];
    int now_count = 0;
    int last_show = 0;

    for (i=0; i<n; i++)
    {
        num = line[i];
        if (now_num != num)
        {
            last_show++;
            if (location == -1)
            {
                location = i;
            }
            if (last_show == 6)
            {
                keep_result(now_num, now_count);
                i = location;
                now_num = line[i];
                now_count = 1;
                last_show = 0;
                location = -1;
                continue;
            }
        }
        else
        {
            now_count++;
            last_show = 0;
        }
        if (i==n-1 && location!=-1)
        {
            keep_result(now_num, now_count);
            i = location;
            now_num = line[i];
            now_count = 1;
            last_show = 0;
            location = -1;
        }
    }
    keep_result(now_num, now_count);

    return;
}

void keep_result(int num, int count)
{
    if (count == max_count)
    {
        if (num < max_num)
        {
            max_num = num;
            max_count = count;
        }
    }
    else if (count > max_count)
    {
        max_num = num;
        max_count = count;
    }

    return;
}