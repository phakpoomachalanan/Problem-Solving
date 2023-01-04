#include <iostream>
#include <vector>

using namespace std;

int n, m;
int best_q=0, good_q=0;
const int MAX_N = 31;
const int MAX_M = 31;
int map[MAX_N][MAX_M] = {0};
bool visited[MAX_N][MAX_M] = {false};

int main(void)
{
    int  i, j;
    char ch;
    string row;

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
            }
            else if (ch == '*')
            {
                map[i][j] = 3;
            }
        }
    }

    /*for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            cout << map[i][j];
        }
        cout << '\n';
    }
    */

    return 0;
}