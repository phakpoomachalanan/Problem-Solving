#include <iostream>
#include <set>

const int MAX_N = 100001;

using namespace std;

int n;
int lines[MAX_N];
int max_l[MAX_N];
int parent[MAX_N];
set<int> max_ans;

void get_input();
void init();

int main(void)
{
    int i, j, temp, max_ai, max_in;

    get_input();
    init();

    for (i=1; i<n; i++)
    {
        temp = lines[i];
        max_ai = max_l[i];
        for (j=0; j<i; j++)
        {
            if (temp>lines[j] && max_ai<=max_l[j])
            {
                parent[i] = j;
                max_ai = max_l[j];
            }
        }
        max_l[i] = max_ai + 1;
    }

    for (max_ai=0, i=0; i<n; i++)
    {
        if (max_l[i] > max_ai)
        {
            max_ai = max_l[i];
            max_in = i;
        }
    }

    while (parent[max_in] != -1)
    {
        max_ans.insert(lines[max_in]);
        max_in = parent[max_in];
    }
    max_ans.insert(lines[max_in]);

    cout << max_ans.size() << '\n';
    for (auto itr: max_ans)
    {
        cout << itr << ' ';
    }
    cout << '\n';
 
    return 0;
}

void get_input()
{
    cin >> n;

    init();
    for (int i=0; i<n; i++)
    {
        cin >> lines[i];
    }

    return;
}

void init()
{
    for (int i=0; i<n; i++)
    {
        parent[i] = -1;
        max_l[i] = 1;
    }
}