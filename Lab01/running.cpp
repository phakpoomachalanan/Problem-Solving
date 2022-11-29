#include <iostream>

int main(void)
{
    int     i, k=0;
    double  candidate, round, min;
    double* period;
    
    std::cin >> candidate >> round;
    period = (double*)malloc(sizeof(double)*candidate);

    std::cin >> period[0];
    min = period[0];
    for (i=1; i<candidate; i++)
    {
        std::cin >> period[i];
        if (period[i] < min)
        {
            min = period[i];
        }
    }
    if (round != 1)
    {
        for (i=0; i<candidate; i++)
        {
            if (min*round/period[i] > round-1)
            {
                k++;
            }
        }
        std::cout << k << "\n";
    }
    else
    {
        std::cout << candidate << "\n";
    }

    return 0;
}