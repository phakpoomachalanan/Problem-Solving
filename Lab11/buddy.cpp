#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n;

void get_input();
void init();
void bfs(int s);

int main(void)
{
    int count = 0;

    get_input();
    init();
    
    for (int i=0; i<n; i++)
    {
        if (layer[i] == -1)
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
    int u, v;

    cin >> n;

    for (i=0; i<n; i++)
    {
        deg[i] = 0;
    }
    for (i=0; i<n; i++)
    {
        cin >> u;
        u--;
        adj[i].push_back(u);
        deg[i]++;
    }
}

void init()
{
    for (int i=0; i<n; i++)
    {
        visited[i] = false;
        layer[i] = -1;
    }
}

void bfs(int s)
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