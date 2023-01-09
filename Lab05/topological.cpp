#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
bool visited[MAX_N];
vector<pair<int, int> > output;
int layer[MAX_N];
int deg[MAX_N];
int n, m;

void get_input();
void init();
bool bfs(int s);

int main(void)
{
    int  i;
    bool flag = true;
    vector<pair<int, int> >::iterator itr;

    get_input();
    init();

    for (int i=0; i<m; i++)
    {
        if (layer[i] == -1)
        {
            if (!bfs(i))
            {
                cout << "no\n";
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        sort(output.begin(), output.end());
        for (itr=output.begin(); itr!=output.end(); itr++)
        {
            cout << itr->second+1 << '\n';
        }
    }

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> m >> n;

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
        deg[u]++;
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

bool bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u, v, i;

    current_layer.push_back(s);
    visited[s] = true;
    layer[s] = 0;

    output.push_back(make_pair(0, s));

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
                    output.push_back(make_pair(layer[v], v));
                }
                else
                {
                    if (u > v)
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