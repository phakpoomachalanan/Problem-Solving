#include <iostream>

int main(void)
{
    int bowls[301]={0};
    int x, times, max;

    std::cin >> times;

    for (int i=0; i<times; i++)
    {
        std::cin >> x;
        bowls[x]++;
        if (bowls[x] > max)
        {
            max = bowls[x];
        }
    }
    std::cout << max << "\n";

    return 0;
}
