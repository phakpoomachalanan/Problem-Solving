#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, m, h;

void get_input();
void init();
int bfs(int s);

int main(void)
{
    int count = 0;
    int max = 0;

    get_input();
    
    for (int i=0; i<m; i++)
    {
        init();
        count = bfs(i);
        if (count > max)
        {
            max = count;
        }
    }

    cout << max << '\n';

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> m >> n >> h;

    for (i=0; i<m; i++)
    {
        deg[i] = 0;
    }
    for (i=0; i<n; i++)
    {
        cin >> u >> v;
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
    }
}

int bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u, v, i;
    int distance = 0;
    int count = 1;

    current_layer.push_back(s);
    visited[s] = true;
    layer[s] = 0;

    while (distance != h)
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
                    count++;
                }
            }
        }
        if (next_layer.size() == 0)
        {
            break;
        }
        current_layer = next_layer;
        next_layer.clear();

        distance++;
    }

    return count;
}