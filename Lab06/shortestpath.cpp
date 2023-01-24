#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
vector<int> wei[MAX_N];
bool visited[MAX_N];
int weight[MAX_N];
int deg[MAX_N];
int n, m;

void get_input();
void init();
void bfs(int s);

int main(void)
{
    int count = 0;

    get_input();
    init();
    
    for (int i=0; i<m; i++)
    {
        if (weight[i] == -1)
        {
            bfs(i);
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}

void get_input()
{
    int i;
    int u, v, w;

    cin >> m >> n;

    for (i=0; i<m; i++)
    {
        deg[i] = 0;
    }
    for (i=0; i<n; i++)
    {
        cin >> u >> v >> w;
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
        weight[i] = -1;
    }
}

void bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u, v, i;

    current_layer.push_back(s);
    visited[s] = true;
    weight[s] = 0;

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
                    weight[v] = weight[u] + 1;
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