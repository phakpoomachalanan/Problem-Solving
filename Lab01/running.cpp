#include <iostream>

int main(void)
{
    int    i, k=0;
    float  candidate, round, min;
    float* period;
    float  out;
    
    std::cin >> candidate >> round;
    period = (float*)malloc(sizeof(float)*candidate);

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
    out = min*round/(round-1);
    for (i=0; i<candidate; i++)
    {
        if (period[i] < out)
        {
            k++;
        }
    }
    std::cout << k << "\n";

    return 0;
}