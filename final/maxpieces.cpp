#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int n, m;
vector<int> table;
int question[MAX_N][2];
int max_piece[MAX_N];
int min_price[MAX_N];

void get_input();
void init();
void print_output(int q);

int main()
{
    int i, j, q;
    int min_y;

    get_input();
    
    for (q=0; q<m; q++)
    {
        i = 0;
        j = 0;
        init();
        min_y = question[q][1];
        for (i=0; i<n; i++)
        {
            if (table[i] < min_y)
            {
                continue;
            }
            max_piece[i] = j+1;
            min_price[i] += i==0 ? table[i] : min_price[i-1]+table[i];
            j++;
        }
        print_output(q);
    }

    return 0;
}

void get_input()
{
    int i, j, temp;

    cin >> n >> m;

    for (i=0; i<n; i++)
    {
        cin >> temp;
        table.push_back(temp);
    }
    for (i=0; i<m; i++)
    {
        cin >> question[i][0] >> question[i][1];
    }
    sort(table.begin(), table.end());

    return;
}

void init()
{
    int i;

    for (i=0; i<n; i++)
    {
        min_price[i] = 0;
        max_piece[i] = 0;
    }

    return;
}

void print_output(int q)
{
    int i, output = 0;
    int max_q = question[q][0];
    int min_y = question[q][1];
    int y = 0;

    for (i=0; i<n; i++)
    {
        if (min_price[i]<=max_q)
        {
            output = max_piece[i];
        }
    }
    
    cout << output << '\n';

    return;
}