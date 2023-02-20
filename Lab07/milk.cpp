#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100001;
const int MAX_M = 200001;

int n, m;
int parent[MAX_N];
int p_size[MAX_N];

void init();
int find(int u);
void union_tree(int u, int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int u, v, i;
    char command;

    cin >> n >> m;

    init();

    for (i=0; i<m; i++)
    {
        cin >> command >> u >> v;
        u--; v--;

        switch (command)
        {
            case 'c':
                union_tree(u, v);
                break;
            case 'q':
                if (find(u) == find(v))
                {
                    cout << "yes\n";
                }
                else
                {
                    cout << "no\n";
                }

        }
    }

    return 0;
}

void init()
{
    for (int i=0; i<n; i++)
    {
        parent[i] = i;
        p_size[i] = 1;
    }
}

int find(int u)
{
    int p = parent[u];

    return p==u ? u : parent[u]=find(p);
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