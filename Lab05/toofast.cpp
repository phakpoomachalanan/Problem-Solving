#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100001;
int n, m;
bool can;
int cost[MAX_N];
bool visited[MAX_N];
int tollway_used[MAX_N];
vector<int> tollway[MAX_N];
vector<pair<int, int> > adj[MAX_N];

void init();
void get_input();
void dijkstra(int start, int end);

int main()
{
    get_input();
    dijkstra(0, n-1);

    if (visited[n-1])
    {
        cout << cost[n-1] << '\n';
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

void init()
{
    can = false;
    for (int i=0; i<n; i++) 
    {
        cost[i] = 0xfffffff;
        visited[i] = false;
        tollway_used[i] = false;
    }

    return;
}

void get_input()
{
    int i, u, v, w, toll;

    cin >> n >> m;
    init();

    for (i=0; i<m; i++)
    {
        cin >> u >> v >> w >> toll;
        u--; v--;
        tollway[u].push_back(toll);
        tollway[v].push_back(toll);
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
        tollway_used[u] = false;
        
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

            // if (tollway[u][v] && tollway_used[u])
            // {
            //     continue;
            // }
            if (cost[u]+w < cost[v])
            {
                cost[v] = cost[u] + w; 
                pq.push(make_pair(cost[v], v));
                // tollway_used[v] = tollway[u][v] || tollway_used[u];
                // cout << u+1 << ' ' << v+1 << ' ' << tollway[u][i] << ' ' << tollway_used[u] << endl;
            }
        }
    }

    // for (i=0; i<n; i++)
    // {
    //     for (int j=0; j<tollway[i].size(); j++)
    //     {
    //         cout << i+1 << ' ' << (adj[i][j].first+1) << ' ' << tollway_used[i] << endl;
    //     }
    // }

    return;
}