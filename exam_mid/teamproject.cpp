#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, m, k;

void get_input();
void init();
bool bfs(int s);

int main(void)
{
    int i;

    get_input();

    if (bfs(i))
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> n >> m >> k;

    init();
    for (i=0; i<m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
    }
}

void init()
{
    for (int i=0; i<n; i++)
    {
        deg[i] = 0;
        adj[i].clear();
        visited[i] = false;
        layer[i] = -1;
    }
}

bool bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u, v, i;

    current_layer.push_back(s);
    visited[s] = true;
    layer[s] = 0;

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
                else
                {
                    if (layer[v]%2==layer[u]%2 && (deg[v]<k || deg[u]<k))
                    {
                        return false;
                    }
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

    return true;
}