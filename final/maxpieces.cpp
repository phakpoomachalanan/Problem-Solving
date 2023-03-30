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
int binary_search(vector<int> table, int l, int r, int x);

int main()
{
    int i, q;
    int min_y;
    int sum_low;
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

        table.push_back(min_y);
        sort(table.begin(), table.end());

        low_i = binary_search(table, 0, n, min_y);
        cout <<"i : " << low_i << endl;
        table.erase(table.begin()+low_i);
        if (low_i == 0)
        {
            low_i = 0;
            sum_low = 0;
        }
        else
        {
            low_i--;
            sum_low = min_price[low_i];
        }

        print_output(q, sum_low, low_i);
    }

    return 0;
}

void get_input()
{
    int i, temp;

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

    for (i=min_i; i<n; i++)
    {
        if (min_price[i]-minus<=max_q)
        {
            output = max_piece[i];
        }
    }
    if (question[q][1] == table[0])
    {
        min_i++;
    }

    cout << output-min_i << '\n';

    return;
}

int binary_search(vector<int> table, int l, int r, int x)
{
    int mid;

    if (r >= l)
    {
        mid = l + (r-l) / 2;
 
        if (table[mid] == x)
        {
            return mid;
        }
 
        if (table[mid] > x)
        {
            return binary_search(table, l, mid - 1, x);
        }
 
        return binary_search(table, mid + 1, r, x);
    }

    return -1;
}

    // int table[] = { 2, 3, 4, 10, 40 };
    // int x = 10;
    // int n = sizeof(table) / sizeof(table[0]);
    // int result = binary_search(table, 0, n - 1, x);