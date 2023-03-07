#include <iostream>
#include <vector>

using namespace std;

int  n, m;
const int MAX_N = 51;
int min_dot = 0xfffffff;
int layer[MAX_N][MAX_N];
bool can, all_can=false;
bool map[MAX_N][MAX_N] = {'\0'};
bool visited[50][50];

void init();
void traversal(int y, int x, int dir, int tick);

int main(void)
{
    int i, j;
    char temp;

    cin >> n >> m;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> temp;
            map[i][j] = temp=='X';
        }
    }

    init();
    traversal(n-1, 0, 0, 0);

    if (all_can)
    {
        cout << layer[0][m-1] << '\n';
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

void init()
{
    int i, j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            layer[i][j] = 0xffff;
        }
    }

    return;
}

void traversal(int y, int x, int plus, int tick)
{
    int curr_layer;

    if (y>n-1 || y<0 || x>m-1 || x<0)
    {
        return;
    }

    if (map[y][x] || visited[y][x])
    {
        return;
    }

    visited[y][x] = true;
    curr_layer = layer[y][x];

    
    if (tick < curr_layer)
    {
        curr_layer = tick + plus;
    }
    // if (layer[y+1][x] <= curr_layer)
    // {
    //     curr_layer = layer[y+1][x];
    // }
    // if (layer[y-1][x] <= curr_layer)
    // {
    //     curr_layer = layer[y-1][x] + 5;
    // }
    // if (layer[y][x+1] <= curr_layer)
    // {
    //     curr_layer = layer[y][x+1] + 1;
    // }
    // if (layer[y][x-1] <= curr_layer)
    // {
    //     curr_layer = layer[y][x-1] + 1;
    // }
    layer[y][x] = curr_layer;

    // cout << y << " " << x << " " << layer[y][x] << " " << tick << endl;

    if (y==0 && x==m-1)
    {
        can = true;
        all_can = true;
        // cout << y << " " << x << " " << layer[y][x] << " " << tick << endl;
        if (curr_layer > tick)
        {
            layer[0][m-1] = tick+plus;
        }
        return;
    }

    traversal(y+1, x, 0, curr_layer);
    traversal(y, x-1, 1, curr_layer);
    traversal(y, x+1, 1, curr_layer);
    traversal(y-1, x, 5, curr_layer);

    return;
}