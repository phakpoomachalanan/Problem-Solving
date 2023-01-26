#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, int> > tasks;
    int n, i, deadline, completein;
    int fare, time=0;
    int max = 0;

    cin >> n;

    for (i=0; i<n; i++)
    {
        cin >> deadline >> completein;
        tasks.push_back(make_pair(deadline, completein));
    }
    sort(tasks.begin(), tasks.end());

    for (i=0; i<n; i++)
    {
        time += tasks[i].second;

        if (time > tasks[i].first + 10)
        {
            fare = (time - tasks[i].first - 10) * 1000;

            if (fare > max)
            {
                max = fare;
            }
        }
    }

    cout << max << '\n';

    return 0;
}