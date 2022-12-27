#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1002;

vector<pair<int, int> > coor;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, r_square;

void get_input();
void create_graph();
void init();
int  bfs(int s);

int main(void)
{
    int times = 0;
    int min = 1002;

    get_input();
    init();
    create_graph();

    for (int i=0; i<n; i++)
    {
        if (layer[i] == -1)
        {
            times = bfs(i);
            if (times != -1 && times < min)
            {
                min = times;
            }
        }
    }
    if (times == 1002)
    {
        cout << "-1\n";
    }
    else 
    {
        cout << times << '\n';
    }

    return 0;
}

void get_input()
{
    pair<int, int> temp;
    int x, y, i;
    cin >> n >> r_square;
    r_square *= r_square;

    temp.first = 0;
    temp.second = 0;
    coor.push_back(temp);
    for (int i=0; i<n; i++)
    {
        cin >> x >> y;
        temp.first = x;
        temp.second = y;
        coor.push_back(temp);
    }
    temp.first = 100;
    temp.second = 100;
    coor.push_back(temp);
}

void create_graph()
{
    int i, j;
    int u, v;
    int rsqr1, rsqr2;
    int dx, dy;
    int diff;

    for (i=0; i<=n+1; i++)
    {
        deg[i] = 0;
    }
    for (i=0; i<=n+1; i++)
    {
        for (j=i+1; j<=n+1; j++)
        {
            dx = coor[j].first - coor[i].first;
            dy = coor[j].second - coor[i].second;
            diff = dx*dx + dy*dy;
            if (diff <= r_square)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                deg[i]++;
                deg[j]++;
            }
        }
    }
}

void init()
{
    for (int i=0; i<=n+1; i++)
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
    int count = 0;

    current_layer.push_back(s);
    visited[s] = true;
    layer[s] = 0;

    while (true)
    {
        count++;
        for (vector<int>::iterator itr=current_layer.begin(); itr!=current_layer.end(); itr++)
        {
            u = *itr;
            for (i=0; i<deg[u]; i++)
            {
                v = adj[u][i];
                if (v == n+1)
                {
                    return count;
                }
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
    return -1;
}