#include <iostream>

using namespace std;

int line[200001];
int rott[200001] = {0};

int main(void)
{
    int size, i;
    int count;
    int max  = 1;

    cin >> size;

    for (i=0; i<size; i++)
    {
        cin >> line[i];
        line[i]--;
    }
    for (i=0; i<size; i++)
    {
        line[i] -= i;
        line[i] = line[i]>0 ? line[i] : size+line[i];
        rott[line[i]] += 1;
    }
    for (i=0; i<size; i++)
    {
        count = rott[i];
        if (count > max)
        {
            max = count;
        }
    }

    cout << max << '\n';

    return 0;
}