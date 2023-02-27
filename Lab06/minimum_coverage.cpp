#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int> > edge;

void get_input();

int main()
{
    int h, i, j, k;
    int head, tail, temp;
    int min_use;
    vector<pair<int, int> > line;
    vector<pair<int, int> > min_line;
    int use;
    bool can;

    cin >> n;

    for (i=0; i<n; i++)
    {
        get_input();

        if (edge.size() == 0)
        {
            cout << "0\n\n";
            continue;
        }
        can = false;
        min_use = 0xfffffff;
        
        for (j=0; j<edge.size(); j++)
        {
            can = can ? true : false;
            use = 1;
            tail = edge[j].first;
            head = edge[j].second;

            line.push_back(edge[j]);

            for (k=j; k<edge.size(); k++)
            {
                if (k == j)
                {
                    continue;
                }
                temp = edge[k].second;
                if (temp == tail)
                {
                    tail = edge[k].first;
                    line.push_back(edge[k]);
                    use++;
                }
            }
            if (head<=0 && tail>=m)
            {
                can = true;

                if (use < min_use)
                {
                    min_line.clear();
                    for (h=0; h<line.size(); h++)
                    {
                        // cout << line[h].second << " " << line[h].first << endl;
                        min_line.push_back(line[h]);
                    }
                    min_use = use;
                }
            }

            line.clear();
        }

        if (can)
        {
            cout << min_use << '\n';
            for (j=0; j<min_line.size(); j++)
            {
                cout << min_line[j].second << ' ' << min_line[j].first << '\n';
            }
        }
        else
        {
            cout << "0\n";
        }
        min_line.clear();

        cout << '\n';
    }

    return 0;
}

void get_input()
{
    int t1, t2;

    edge.clear();
    cin >> m;

    while (true)
    {
        cin >> t1 >> t2;
        if (t1==0 && t2==0)
        {
            break;
        }
        if (t2<0 || t1>m)
        {
            continue;
        }
        edge.push_back(make_pair(t2, t1));
    }

    sort(edge.begin(), edge.end());
}