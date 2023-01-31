#include <iostream>
#include <vector>

using namespace std;

int  n, m;
int des_y, des_x;
int sta_y, sta_x;
int spe_y, spe_x;
const int MAX_N = 51;
int min_visa = 0xfffffff;
bool can, all_can=false;
int map[MAX_N][MAX_N] = {0};
bool visited[MAX_N] = {false};
vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];

void init();
void bfs(int s);

int main(void)
{
    int i, j, u, v, w;

    cin >> n >> m;
    cin >> sta_y >> sta_x >> des_y >> des_x;
    sta_y--; sta_x--; des_y--; des_x--;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<m-1; j++)
        {
            u = map[i][j];
            v = map[i][j+1];
            if (u != v)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
                deg[u]++;
                deg[v]++;
            }
            if (i != n-1)
            {
                w = map[i+1][j];
                if (u != w)
                {
                    adj[u].push_back(w);
                    adj[w].push_back(u);
                    deg[u]++;
                    deg[w]++;
                }
            }
        }
    }

    cout << layer[map[des_y][des_x]] << '\n';

    return 0;
}

void init()
{
    int i, j;

    can = false;
    for (j=0; j<m; j++)
    {
        visited[j] = false;
    }

    return;
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