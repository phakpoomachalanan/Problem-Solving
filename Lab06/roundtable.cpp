#include <iostream>

using namespace std;

int main(void)
{
    int size, last, i, now, first;
    int count = 1;
    int max  = 1;
    bool ordered = false;
    bool plused = false;

    cin >> size;
    cin >> first;
    last = first;

    for (i=1; i<size; i++)
    {
        cin >> now;

        if (last+1 == now || (last+1)%size == now)
        {
            if (ordered)
            {
                count++;
            }
            else
            {
                count = 2;
                ordered = true;
            }
            if (i == 1)
            {
                plused = true;
            }
        }
        else
        {
            ordered = false;
        }
        if (count > max)
        {
            max = count;
        }

        last = now;
    }
    if (!plused && last+1 == first)
    {
        count++;

        if (count > max)
        {
            max = count;
        }
    }

    cout << max << '\n';

    return 0;
}