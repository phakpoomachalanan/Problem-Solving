#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 200001;

int n, m;
vector<int> speed;
int parent[MAX_N];
int p_size[MAX_N];
int edge[MAX_M][2];
pair<int, int> sorted_edge[MAX_M];

void get_input();
int find(int u);
void union_tree(int u, int v);

int main(void)
{
    int i, u, v, e;
    int result = 0;

    get_input();
    sort(sorted_edge, sorted_edge+m);

    for (i=0; i<m; i++)
    {
        e = sorted_edge[i].second;
        u = edge[e][0];
        v = edge[e][1];

        if (find(u) != find(v))
        {
            union_tree(u, v);
            result = sorted_edge[i].first;
        }
    } 
    cout << result << '\n';

    return 0;
}

void get_input()
{
    int i, temp;
    double u, v, w;
    double time;

    cin >> n >> m;

    for (i=0; i<m; i++)
    {
        parent[i] = i;
        p_size[i] = 1;
    }
    for (i=0; i<n; i++)
    {
        cin >> temp;
        speed.push_back(temp);
    }
    for (i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        u--; v--;

        edge[i][0] = (int)u;
        edge[i][1] = (int)v;
        time = w/(speed[u]+speed[v]);
        if ((int)time != time)
        {
            time = (int)time + 1;
        }
        sorted_edge[i].first = time;
        sorted_edge[i].second = i;
    }
}

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    parent[u] = find(parent[u]);

    return parent[u];
}

void union_tree(int u, int v)
{
    int temp;

    v = find(v);
    u = find(u);
    if (p_size[u] > p_size[v])
    {
        temp = u;
        u = v;
        v = temp;
    }
    parent[u] = v;
    p_size[v] += p_size[u];
}