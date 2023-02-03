#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100001;
int n, m;
int cost[MAX_N];
bool visited[MAX_N];
vector<pair<int, int> > adj[MAX_N];

void init();
void get_input();
void dijkstra(int start, int end);

int main()
{
    get_input();
    dijkstra(0, n-1);

    cout << cost[n-1] << '\n';

    return 0;
}

void init()
{
    for (int i=0; i<n; i++) 
    {
        cost[i] = 0xfffffff;
        visited[i] = false;
    }

    return;
}

void get_input()
{
    int i, u, v, w;

    cin >> n >> m;
    init();

    for (i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    return;
}

void dijkstra(int start, int end)
{
    int i;
    int u, v, w;
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    cost[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        
        if (visited[u])
        {
            continue;
        }
        
        visited[u] = true;
        
        if (u == end) 
        {
            break;
        }
        
        for (i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i].first;
            w = adj[u][i].second;

            if (cost[u]+w < cost[v])
            {
                cost[v] = cost[u] + w; 
                pq.push(make_pair(cost[v], v));
            }
        }
    }

    return;
}