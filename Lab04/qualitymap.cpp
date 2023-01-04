#include <iostream>
#include <vector>

using namespace std;

int n, m, block;
int best_q=0, good_q=0;
bool flag;
const int MAX_N = 31;
const int MAX_M = 31;
int map[MAX_N][MAX_M] = {0};
bool visited[MAX_N][MAX_M] = {false};

void find_quality(int y, int x, int spe);

int main(void)
{
    int  i, j, temp;
    char ch;
    string row;
    vector<pair<int, int> > coor;

    cin >> n >> m;
    getline(cin, row);

    for (i=0; i<n; i++)
    {
        getline(cin, row);
        for (j=0; j<m; j++)
        {
            ch = row[j];
            if (ch == '.')
            {
                map[i][j] = 1;
            }
            else if (ch == '$')
            {
                map[i][j] = 2;
                coor.push_back(make_pair(i, j));
            }
            else if (ch == '*')
            {
                map[i][j] = 3;
                coor.push_back(make_pair(i, j));
            }
        }
    }

    for (i=0; i<coor.size(); i++)
    {
        if (!visited[coor[i].first][coor[i].second])
        {
            block = 0;
            flag = false;
            
            find_quality(coor[i].first, coor[i].second, map[coor[i].first][coor[i].second]);

            if (flag)
            {
                best_q += block;
            }
            else
            {
                good_q += block;
            }
        }
    }

    cout << best_q << ' ' << good_q << '\n';

    return 0;
}

void find_quality(int y, int x, int spe)
{
    if (y>=n || y<0 || x>=m || x<0)
    {
        return;
    }
    if (map[y][x] == 0 || visited[y][x])
    {
        return;
    }

    visited[y][x] = true;
    if (spe == 2 && map[y][x] == 3)
    {
        flag = true;
    }
    else if (spe == 3 && map[y][x] == 2)
    {
        flag = true;
    }
    block++;

    find_quality(y+1, x, spe);
    find_quality(y-1, x, spe);
    find_quality(y, x+1, spe);
    find_quality(y, x-1, spe);

    return;
}