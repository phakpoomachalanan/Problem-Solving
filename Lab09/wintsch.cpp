#include <iostream>
#include <vector>

using namespace std;

struct Interval
{
    int start, end, weight;
};

const int MAX_N = 1001;
int n;
vector<int> dp(MAX_N);
vector<int> parent(MAX_N, -1);
vector<Interval> intervals(MAX_N);

void get_input();
void init();

int main()
{
    int i, j;
    int index;
    int maxIndex = 0;
    vector<int> indices;

    get_input();

    for (i=0; i<n; i++)
    {
        dp[i] = intervals[i].weight;
        for (j=i-1; j>=0; j--)
        {
            if (intervals[j].end <= intervals[i].start)
            {
                if (dp[j] + intervals[i].weight > dp[i])
                {
                    dp[i] = dp[j] + intervals[i].weight;
                    parent[i] = j;
                }
            }
        }
    }

    for (i=1; i<n; i++)
    {
        if (dp[i] > dp[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << dp[maxIndex] << endl;
    
    index = maxIndex;
    while (index != -1)
    {
        indices.push_back(index);
        index = parent[index];
    }

    cout << indices.size() << endl;
    for (i=indices.size()-1; i>=0; i--)
    {
        cout << indices[i]+1 << " ";
    }
    cout << endl;

    return 0;
}

void get_input()
{
    cin >> n;

    init();
    for (int i=0; i<n; i++)
    {
        cin >> intervals[i].start >> intervals[i].end >> intervals[i].weight;
    }

    return;
}

void init()
{
    for (int i=0; i<n; i++)
    {
        dp[i] = 0;
        parent[i] = -1;
    }

    return;
}