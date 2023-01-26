#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int MAX_N = 100001;

vector<int> adj[MAX_N];
vector<int> factory;
vector<int> supply;
int dis[50001];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, m, s, t;

void get_input();
void init();
void bfs(int s);

int main(void)
{
    int i, j, temp;

    get_input();

    for (i=0; i<s; i++)
    {
        init();
        bfs(supply[i]);

        for (j=0; j<t; j++)
        {
            temp = factory[j];

            if (dis[j] > layer[temp])
            {
                dis[j] = layer[temp];
            }
        }
    }

    for (i=0; i<t; i++)
    {
        cout << dis[i] << '\n';
    }

    return 0;
}

void get_input()
{
    int i;
    int u, v;

    cin >> m >> n >> s >> t;

    for (i=0; i<m; i++)
    {
        deg[i] = 0;
        layer[i] = -1;
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
    for (i=0; i<s; i++)
    {
        cin >> u; u--;
        supply.push_back(u);
    }
    for (i=0; i<t; i++)
    {
        cin >> u; u--;
        factory.push_back(u);
        dis[i] = 0xffff;
    }
}

void init()
{
    for (int i=0; i<m; i++)
    {
        visited[i] = false;
    }
}

void bfs(int s)
{
    list<int> Q;

    Q.push_back(s);
    visited[s] = true;
    layer[s] = 0;
    
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