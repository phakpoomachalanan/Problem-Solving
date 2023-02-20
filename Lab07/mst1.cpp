#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;
const int MAX_M = 100001;

int n, m;
int parent[MAX_N];
int p_size[MAX_N];
int edge[MAX_M][2];
pair<int, int> sorted_edge[MAX_M];


void read_input();
int find(int u);
void union_tree(int u, int v);

int main(void)
{
    int u, v, e, i;
    int result = 0;

    read_input();
    sort(sorted_edge, sorted_edge+m);

    for (i=0; i<m; i++)
    {
        e = sorted_edge[i].second;
        u = edge[e][0];
        v = edge[e][1];

        if (find(u) != find(v))
        {
            union_tree(u, v);
            result += sorted_edge[i].first;
        }
    } 
    cout << result << '\n';

    return 0;
}

void read_input()
{
    int i;
    int u, v, w;

    cin >> n >> m;
    for (i=0; i<n; i++)
    {
        parent[i] = i;
        p_size[i] = 1;
    }
    for (i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        u--; v--;
        edge[i][0] = u;
        edge[i][1] = v;
        sorted_edge[i].first = w;
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