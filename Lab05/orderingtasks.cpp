#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

int n, m;
int in_deg[MAX_N];
int out_deg[MAX_N];
bool can;
bool visited[MAX_N];
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

        if (n==0 && m==0)
        {
            break;
        }
        init();
        read_input();
        topo_order();

        if (can)
        {
            for (i=0; i<m-1; i++)
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

    for (i=0; i<m; i++)
    {
        in_deg[i] = 0;
        out_deg[i] = 0;
        visited[i] = false;
        adj[i].clear();
    }

    can = true;
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
        out_deg[u]++;
    }
}

void topo_order()
{
    vector<int> s;
    int i, u, v;

    for (i=0; i<n; i++)
    {
        if (in_deg[i] == 0)
        {
            s.push_back(i);
        }
    }
    if (s.empty())
    {
        can = false;
        return;
    }

    while (!s.empty())
    {
        u = s.back();
        s.pop_back();
        visited[u] = 1;
        output.push_back(u);

        for (i=0; i<out_deg[u]; i++)
        {
            v = adj[u][i];
            in_deg[v]--;
            if (in_deg[v] == 0)
            {
                s.push_back(v);
            }
        }
    }
}