#include <iostream>
#include <vector>

using namespace std;

int spe_y, spe_x;
int  n, m;
bool can;
const int MAX_N = 51;
bool map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N] = {false};
vector<pair<int, int> > speacial;
int layer[MAX_N][MAX_N];
int des_y, des_x;

void get_input();
void init();
void traversal(int y, int x, int tick);

int main(void)
{
    int min = 0xfffffff;
    int i, j;

    traversal(n-1, 0, 0);

    if (can)
    {
        cout << min << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}

void get_input()
{
    int i, j, temp;

    cin >> n >> m;

    init();
    
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> temp;
            map[i][j] = (temp=='X');
        }
    }
}

void init()
{
    int i, j;

    can = false;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            visited[i][j] = false;
            layer[i][j] = 0xffff;
            map[i][j] = 0;
        }
    }

    des_x = m-1;
    des_y = 0;

    return;
}

void traversal(int y, int x, int tick)
{
    if (y>n-2 || y<1 || x>m-2 || x<1)
    {
        return;
    }
    if (map[y][x] || visited[y][x])
    {
        return;
    }

    visited[y][x] = true;
    // if (tick < layer[y][x])
    // {
    //     layer[y][x] = tick + 1;
    // }
    // if (layer[y+1][x] <= layer[y][x])
    // {
    //     layer[y][x] = layer[y+1][x] + 1;
    // }
    // if (layer[y-1][x] <= layer[y][x])
    // {
    //     layer[y][x] = layer[y-1][x] + 1;
    // }
    // if (layer[y][x+1] <= layer[y][x])
    // {
    //     layer[y][x] = layer[y][x+1] + 1;
    // }
    // if (layer[y][x-1] <= layer[y][x])
    // {
    //     layer[y][x] = layer[y][x-1] + 1;
    // }

    if (y==des_y && x==des_x)
    {
        // cout << tick << '\n';
        can = true;
        return;
    }

    traversal(y+1, x, layer[y][x]);
    traversal(y-1, x, layer[y][x]);
    traversal(y, x-1, layer[y][x]);
    traversal(y, x+1, layer[y][x]);

    return;
}