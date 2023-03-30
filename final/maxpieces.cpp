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
void print_output(int q, int minus, int min_i);

int main()
{
    int i, q;
    int min_y;
    int sum_lower;
    int low_i;

    get_input();
    
    for (i=0; i<n; i++)
    {
        max_piece[i] = i+1;
        min_price[i] += i==0 ? table[i] : min_price[i-1]+table[i];
    }
    for (q=0; q<m; q++)
    {
        min_y = question[q][1];
        sum_lower = 0;
        low_i = 0;
        for (i=0; i<n; i++)
        {
            if (table[i] < min_y)
            {
                sum_lower += table[i];
                low_i++;
            }
            else
            {
                break;
            }
        }
        print_output(q, sum_lower, low_i);
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

void print_output(int q, int minus, int min_i)
{
    int i, output = 0;
    int max_q = question[q][0];
    int min_y = question[q][1];

    for (i=min_i; i<n; i++)
    {
        if (min_price[i]-minus<=max_q)
        {
            output = max_piece[i];
        }
    }

    output = output>min_i ? output-min_i : 0;
    
    cout << output << '\n';

    return;
}