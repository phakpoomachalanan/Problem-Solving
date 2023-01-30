#include <iostream>
#include <vector>

using namespace std;

int  n, m;
int des_y, des_x;
int sta_y, sta_x;
int spe_y, spe_x;
const int MAX_N = 51;
int min_dot = 0xfffffff;
int layer[MAX_N][MAX_N];
bool can, all_can=false;
int map[MAX_N][MAX_N] = {0};
vector<pair<int, int> > speacial;
bool visited[MAX_N][MAX_N] = {false};

void init();
void pre_travel(int mode);
void traversal(int y, int x, int dir, int tick);

int main(void)
{
    int i, j;

    cin >> n >> m;
    cin >> sta_y >> sta_x >> des_y >> des_x;
    sta_y--; sta_x--; des_y--; des_x--;

    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cin >> map[i][j];
        }
    }

    cout << layer[des_y][des_x] << '\n';

    return 0;
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
        }
    }
    layer[des_y][des_x] = 0xffff;

    return;
}

void traversal(int y, int x, int last_layer)
{
    int curr_layer;

    if (y>n-1 || y<0 || x>m-1 || x<0)
    {
        return;
    }
    if (visited[y][x])
    {
        return;
    }

    visited[y][x] = true;
    curr_layer = layer[y][x];
    
    if (curr_layer != last_layer)
    {
        layer[y][x]++;
    }

    if (y==des_y && x==des_x)
    {
        can = true;
        return;
    }

    traversal(y+1, x, curr_layer);
    traversal(y-1, x, curr_layer);
    traversal(y, x-1, curr_layer);
    traversal(y, x+1, curr_layer);

    return;
}