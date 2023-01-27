#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
bool visited[MAX_N];
bool can = false;
int layer[MAX_N];
int deg[MAX_N];
int color[MAX_N];
int n, m, start, stop;

void get_input();
void init();
void bfs(int start, int stop);

int main(void)
{

    get_input();
    init();
    
    bfs(start, stop);

    if (can)
    {
        cout << layer[stop] << '\n';
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> m >> n >> start >> stop;
    start--; stop--;

    for (i=0; i<m; i++)
    {
        deg[i] = 0;
    }
    for (i=0; i<n; i++)
    {
        cin >> u >> v >> color[i];
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

void init()
{
    for (int i=0; i<m; i++)
    {
        visited[i] = false;
        layer[i] = -1;
        color[i] = 0;
    }
}

void bfs(int start, int stop)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u, v, i;

    current_layer.push_back(start);
    visited[start] = true;
    layer[start] = 0;

    while (true)
    {
        for (vector<int>::iterator itr=current_layer.begin(); itr!=current_layer.end(); itr++)
        {
            u = *itr;
            for (i=0; i<deg[u]; i++)
            {
                v = adj[u][i];
                if (!visited[v])
                {
                    next_layer.push_back(v);
                    visited[v] = true;
                    layer[v] = layer[u] + 1;
                }
                if (v = stop)
                {
                    can = true;
                    return;
                }
            }
        }
        if (next_layer.size() == 0)
        {
            break;
        }
        current_layer = next_layer;
        next_layer.clear();
    }
}