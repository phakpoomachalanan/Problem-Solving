#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, int> > paired;
    int n, i, last_f, last_s;
    int first, second;
    int count = 1;

    cin >> n;

    for (i=0; i<n; i++)
    {
        cin >> second >> first;
        paired.push_back(make_pair(first, second));
    }

    sort(paired.begin(), paired.end());
    last_f = paired[i].first;
    last_s = paired[i].second;

    for (i=1; i<n; i++)
    {
        first = paired[i].first;
        second = paired[i].second;
        
        if ((first>last_f) && (second>=last_f))
        {
            count++;
            last_f = first;
            last_s = second;
        }
    }

    cout << count << '\n';

    return 0;
}