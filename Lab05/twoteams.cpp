#include <iostream>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 200001;

int n, m, day;
int breakpoint;
int layer[MAX_N];
int parent[MAX_N];
int p_size[MAX_N];

void init();
int find(int u);
void union_tree(int u, int v);

int main()
{
    int u, v, i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    for (i=0; i<m; i++)
    {
        cin >> u >> v;
        u--; v--;

        union_tree(u, v);
    }

    cout << breakpoint << '\n';

    return 0;
}

void init()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        parent[i] = i;
        p_size[i] = 1;
        layer[i] = -1;
    }
    day = 0;
    breakpoint = -1;
}

int find(int u)
{
    int p = parent[u];

    return p==u ? u : parent[u]=find(p);
}

void union_tree(int u, int v)
{
    int temp;

    if (layer[u] == -1)
    {
        layer[u] = 0;
    }
    if (breakpoint==-1 && layer[u]%2==layer[v]%2 && layer[v]!=-1)
    {
        if (find(u) == find(v))
        {
            breakpoint = day;
        }
    }
    layer[v] = layer[u] + 1;
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
    day++;
}