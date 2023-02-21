#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 200001;

int n, m;
int parent[MAX_N];
int p_size[MAX_N];
int edge[MAX_M][2];
bool visited[MAX_M];
set<pair<int, int> > sorted_edge;


void read_input();
int find(int u);
void union_tree(int u, int v);

int main(void)
{
    read_input();

    return 0;
}

void read_input()
{
    int i, j, e, result;
    int u, v, w;
    bool status;

    cin >> n >> m;
    for (i=0; i<n; i++)
    {
        parent[i] = i;
        p_size[i] = 1;
        visited[i] = false;
    }
    for (i=0; i<m; i++)
    {
        result = 0;
        status = false;

        cin >> u >> v >> w;
        u--; v--;

        edge[i][0] = u;
        edge[i][1] = v;
        sorted_edge.insert(make_pair(w, i));
        visited[u] = true;
        visited[v] = true;        

        for (j=0; j<n; j++)
        {
            parent[j] = j;
            p_size[j] = 1;
            if (!status && !visited[j])
            {
                status = true;
            }
        }

        if (status)
        {
            cout << "-1\n";
            continue;
        }

        for (auto k: sorted_edge)
        {
            e = k.second;
            u = edge[e][0];
            v = edge[e][1];

            if (find(u) != find(v))
            {
                union_tree(u, v);
                result += k.first;
            }
        }
        cout << result << '\n';

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