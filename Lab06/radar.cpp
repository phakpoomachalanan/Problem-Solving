#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 10001;

vector<pair<int, int> > coor;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int layer[MAX_N];
int deg[MAX_N];
int n, r_square;
int max_radius;
int x, y;

void get_input();
// void sth();

int main(void)
{
    int t = 1;
    int count = 0;
    int min = 10001;

    do
    {
        get_input();
        if (n==0 && max_radius==0)
        {
            break;
        }

        for (int i=0; i<n; i++)
        {
            if (layer[i] == -1)
            {
                count++;
                // sth()
            }
        }
        cout << "case " << t << ": " << count << '\n';

        t++; 
        count = 0;
    }
    while(true);

    return 0;
}

void get_input()
{
    cin >> n >> max_radius;

    for (int i=0; i<n; i++)
    {
        cin >> x >> y;
        coor.push_back(make_pair(x, y));
    }
}