#include <iostream>

int main(void)
{
    int  n, i, mode, last, now;
    int* out;

    std::cin >> n >> mode;
    out = (int*)malloc(sizeof(int)*n);
    last = n;
    for (i=0; i<n; i++)
    {
        std::cin >> now;
        if (last > now)
        {
            out[i] = 0;
        }
        else if (now == last*2 - 1)
        {
            out[i] = 0;
        }
        else
        {
            out[i] = 1;
        }
        last = now;
    }
    for (i=0; i<n; i++)
    {
        std::cout << out[i] << "\n";
    }

    return 0;
}