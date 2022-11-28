#include <iostream>

int main(void)
{
    int num, times, sum=0;

    std::cin >> times;

    for (int i=0; i<times; i++)
    {
        std::cin >> num;
        if (num > 0)
        {
            sum += num;
        }
    }
    std::cout << sum << "\n";

    return 0;
}
