#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
vector<int> factory;
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, m, s, t;
list<int> Q;

void get_input();
void init();
void bfs(int s);

int main(void)
{
    int i, j, temp;

    get_input();
    bfs(Q.front());

    for (i=0; i<t; i++)
    {
        cout << layer[factory[i]] << '\n';
    }

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> m >> n >> s >> t;

    init();

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
    for (i=0; i<s; i++)
    {
        cin >> u; u--;
        Q.push_back(u);
        visited[u] = true;
        layer[u] = 0;
    }
    for (i=0; i<t; i++)
    {
        cin >> u; u--;
        factory.push_back(u);
    }
}

void init()
{
    for (int i=0; i<m; i++)
    {
        deg[i] = 0;
        visited[i] = false;
        layer[i] = -1;
    }
}

void bfs(int s)
{   
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<deg[u]; d++)
        {
            int v = adj[u][d];
            if(!visited[v])
            {
                Q.push_back(v);
                visited[v] = true;
                layer[v] = layer[u] + 1;
            }
        }
    }
}