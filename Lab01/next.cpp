#include <iostream>

int main(void)
{
    int n, j, max=0, k;
    int *send;

    std::cin >> n;
    send = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        std::cin >> send[i];
    }
    for (int i=0; i<n; i++)
    {
        j = i;
        do
        {
            j = send[j-1];
            k++;
        }
        while (j != i);
        if (k > max)
        {
            max = k;
        }
    }
    std::cout << max+1 << "\n";

    return 0;
}
