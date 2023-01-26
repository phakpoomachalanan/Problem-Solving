#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    vector<pair<int, int> > paired;
    int n, i, last_f;
    int first, second;
    int count = 1;

    cin >> n;

    for (i=0; i<n; i++)
    {
        cin >> second >> first;
        paired.push_back(make_pair(first, second));
    }

    sort(paired.begin(), paired.end());
    last_f = 0;

    for (i=0; i<n; i++)
    {
        first = paired[i].first;
        second = paired[i].second;
        
        if ((first>last_f) && (second>=last_f))
        {
            count++;
            last_f = first;
        }
    }

    cout << count-1 << '\n';

    return 0;
}