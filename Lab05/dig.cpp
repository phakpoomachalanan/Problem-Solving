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
char map[MAX_N][MAX_N] = {'\0'};
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
            if (map[i][j] == '*')
            {
                speacial.push_back(make_pair(i, j));
            }
        }
    }

    pre_travel(0);

    for (i=0; i<speacial.size(); i++)
    {
        spe_y = speacial[i].first;
        spe_x = speacial[i].second;

        pre_travel(1);
        pre_travel(2);
    }

    if (all_can)
    {
        cout << min_dot-1 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}

void init()
{
    int i, j;

    can = false;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            visited[i][j] = false;
            layer[i][j] = 0xffff;
        }
    }
    layer[des_y][des_x] = 0xffff;

    return;
}

void pretravel(int mode)
{
    init();
    if (mode == 1)
    {
        map[spe_y][spe_x] = '_';
    }
    else if (mode == 2)
    {
        map[spe_y][spe_x] = '|';
    }
    traversal(sta_y, sta_x, 0, 0);
    all_can = all_can ? all_can : can;
    if (can && layer[des_y][des_x] < min_dot)
    {
        min_dot = layer[des_y][des_x];
    }
    if (mode != 0)
    {
        map[spe_y][spe_x] = '*';
    }

    return;
}

void traversal(int y, int x, int dir, int tick)
{
    int curr_layer;

    if (y>n-2 || y<1 || x>m-2 || x<1)
    {
        return;
    }
    if (map[y][x]=='#' || map[y][x]=='*' || visited[y][x])
    {
        return;
    }
    if ((map[y][x]=='|' && dir!=1)  || (map[y][x]=='_' && dir!=2))
    {
        return;
    }

    visited[y][x] = true;
    curr_layer = layer[y][x];
    
    if (tick < curr_layer)
    {
        curr_layer = tick + 1;
    }
    if (layer[y+1][x] <= curr_layer)
    {
        curr_layer = layer[y+1][x] + 1;
    }
    if (layer[y-1][x] <= curr_layer)
    {
        curr_layer = layer[y-1][x] + 1;
    }
    if (layer[y][x+1] <= curr_layer)
    {
        curr_layer = layer[y][x+1] + 1;
    }
    if (layer[y][x-1] <= curr_layer)
    {
        curr_layer = layer[y][x-1] + 1;
    }
    layer[y][x] = curr_layer;

    if (y==des_y && x==des_x)
    {
        can = true;
        if (curr_layer > tick)
        {
            curr_layer = tick;
        }
        return;
    }
    if (map[y][x]=='|' && dir==1)
    {
        traversal(y+1, x, 1, curr_layer);
        traversal(y-1, x, 1, curr_layer);
        return; 
    }
    if (map[y][x]=='_' && dir==2)
    {
        traversal(y, x+1, 2, curr_layer);
        traversal(y, x-1, 2, curr_layer);
        return; 
    }

    traversal(y+1, x, 1, curr_layer);
    traversal(y-1, x, 1, curr_layer);
    traversal(y, x-1, 2, curr_layer);
    traversal(y, x+1, 2, curr_layer);

    return;
}