#include <iostream>

int main(void)
{
    int  n, i, j, base, k=0;
    int* degree;

    std::cin >> n;
    degree = (int*)malloc(sizeof(int)*n);
    for (i=0; i<n; i++)
    {
        std::cin >> degree[i];
    }
    for (i=0; i<n; i++)
    {
        base = degree[i];
        for (j=i; j<n; j++)
        {
            if (base < degree[j])
            {
                k++;
            }
        }
    }
    std::cout << k << "\n";

    return 0;
}