#include <iostream>
#include <vector>
#include <set>

using namespace std;

int  n, m;
int start, stop;
const int MAX_N = 51;
int map[MAX_N][MAX_N] = {0};
set<int> adj[MAX_N];
bool visited[MAX_N*MAX_N];
int layer[MAX_N*MAX_N];
int deg[MAX_N*MAX_N];

void init();
void bfs(int s);

int main(void)
{
    int i, j, u, v, w;
    int des_y, des_x;
    int sta_y, sta_x;

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

    start = map[sta_y][sta_x];
    stop = map[des_y][des_x];

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            u = map[i][j];
            v = map[i][j+1];
            w = map[i+1][j];
            if (u!=v && v!=0)
            {
                adj[u].insert(v);
            }
            if (u!=w && w!=0)
            {
                adj[u].insert(w);
            }
        }
    }

    bfs(start);

    cout << layer[stop] << '\n';

    return 0;
}

void init()
{
    int i, j;

    for (i=0; i<MAX_N; i++)
    {
        for (j=0; j<MAX_N; j++)
        {
          map[i][j] = 0;
        }
    }
    for (i=0; i<MAX_N*MAX_N; i++)
    {
        visited[i] = false;
        layer[i] = -1;
        deg[i] = 0;
    }

    return;
}

void bfs(int s)
{
    vector<int> current_layer;
    vector<int> next_layer;
    int u;

    current_layer.push_back(s);
    visited[s] = true;
    layer[s] = 0;

    while (true)
    {
        for (vector<int>::iterator itr=current_layer.begin(); itr!=current_layer.end(); itr++)
        {
            u = *itr;
            for (auto v: adj[u])
            {
                if (!visited[v])
                {
                    next_layer.push_back(v);
                    visited[v] = true;
                    layer[v] = layer[u] + 1;
                    // cout << u << " " << v << endl;
                }
                if (v == stop)
                {
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