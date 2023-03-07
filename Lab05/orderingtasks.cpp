#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n, m;
int in_deg[MAX_N];
bool can;
vector<int> output;
vector<int> adj[MAX_N];

void init();
void read_input();
void topo_order();

int main(void)
{
    int i;

    while (true)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }
        init();
        read_input();
        topo_order();

        if (can)
        {
            for (i=0; i<n-1; i++)
            {
                cout << output[i] + 1 << ' ';
            }
            cout << output[n-1] + 1 << '\n';
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}

void init()
{
    int i;

    for (i=0; i<n; i++)
    {
        in_deg[i] = 0;
        adj[i].clear();
    }
    can = true;
    output.clear();

    return;
}

void read_input()
{
    int i, u, v;

    init();

    for (i=0; i<m; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        in_deg[v]++;
    }

    return;
}

void topo_order()
{
    int u, v, i;
    queue<int> q;

    for (i=0; i<n; i++)
    {
        if (in_deg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        u = q.front();
        q.pop();
        output.push_back(u);

        for (i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            in_deg[v]--;

            if (in_deg[v] == 0)
            {
                q.push(v);
            }
        }
    }

    return;
}