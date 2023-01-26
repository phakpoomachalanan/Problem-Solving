#include <iostream>
#include <vector>

using namespace std;

int spe_y, spe_x;
int  n, m;
bool can, all_can=false;
const int MAX_N = 51;
char map[MAX_N][MAX_N] = {'\0'};
bool visited[MAX_N][MAX_N] = {false};
vector<pair<int, int> > speacial;
int layer[MAX_N][MAX_N];
int des_y, des_x;

void init();
void traversal(int y, int x, int dir, int tick);

int main(void)
{
    int min = 0xfffffff;
    int i, j;
    int sta_y, sta_x;

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

    init();
    traversal(sta_y, sta_x, 0, 0);
    all_can = all_can ? all_can : can;
    if (can && layer[des_y][des_x] < min)
    {
        min = layer[des_y][des_x];
    }

    for (i=0; i<speacial.size(); i++)
    {
        spe_y = speacial[i].first;
        spe_x = speacial[i].second;

        init();
        map[spe_y][spe_x] = '|';
        traversal(sta_y, sta_x, 0, 0);
        all_can = all_can ? all_can : can;
        if (can && layer[des_y][des_x] < min)
        {
            min = layer[des_y][des_x];
        }
        map[spe_y][spe_x] = '*';
        
        init();
        map[spe_y][spe_x] = '_';
        traversal(sta_y, sta_x, 0, 0);
        all_can = all_can ? all_can : can;
        if (can && layer[des_y][des_x] < min)
        {
            min = layer[des_y][des_x];
        }
        map[spe_y][spe_x] = '*';
    }

    if (all_can)
    {
        cout << min << '\n';
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

void traversal(int y, int x, int dir, int tick)
{
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
    if (tick < layer[y][x])
    {
        layer[y][x] = tick + 1;
    }
    if (layer[y+1][x] <= layer[y][x])
    {
        layer[y][x] = layer[y+1][x] + 1;
    }
    if (layer[y-1][x] <= layer[y][x])
    {
        layer[y][x] = layer[y-1][x] + 1;
    }
    if (layer[y][x+1] <= layer[y][x])
    {
        layer[y][x] = layer[y][x+1] + 1;
    }
    if (layer[y][x-1] <= layer[y][x])
    {
        layer[y][x] = layer[y][x-1] + 1;
    }

    if (y==des_y && x==des_x)
    {
        // cout << tick << '\n';
        can = true;
        if (layer[y][x] > tick)
        {
            layer[y][x] = tick;
        }
        return;
    }
    if (map[y][x]=='|' && dir==1)
    {
        traversal(y+1, x, 1, layer[y][x]);
        traversal(y-1, x, 1, layer[y][x]);
        return; 
    }
    if (map[y][x]=='_' && dir==2)
    {
        traversal(y, x+1, 2, layer[y][x]);
        traversal(y, x-1, 2, layer[y][x]);
        return; 
    }

    traversal(y+1, x, 1, layer[y][x]);
    traversal(y-1, x, 1, layer[y][x]);
    traversal(y, x-1, 2, layer[y][x]);
    traversal(y, x+1, 2, layer[y][x]);

    return;
}