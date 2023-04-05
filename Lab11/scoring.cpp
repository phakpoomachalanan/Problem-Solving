#include <iostream>

using namespace std;

const int MAX_N = 101;

int n, m;
int score[MAX_N];
int times[MAX_N];

void get_input();
void init();
int sum();

int main()
{
    get_input();
    cout << sum() << '\n';

    return 0;
}

void get_input()
{
    int i, temp_p, temp_s;

    cin >> n >> m;

    init();

    for (i=0; i<m; i++)
    {
        cin >> temp_p >> temp_s;
        temp_p--;
        if (temp_s > score[temp_p])
        {
            score[temp_p] = temp_s;
        }
        times[temp_p]++;
    }

    return;
}

void init()
{
    int i;

    for (i=0; i<n; i++)
    {
        score[i] = 0;
        times[i] = 0;
    }

    return;
}

int sum()
{
    int i, sum = 0;

    for (i=0; i<n; i++)
    {
        sum += times[i]>5 ? 0 : score[i];
    }

    return sum;
}