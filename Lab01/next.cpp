#include <iostream>

int main(void)
{
    int  n, i, j, k=0, max=0;
    int* send, *temp;

    std::cin >> n;
    send = (int*)malloc(sizeof(int)*(n+1));
    temp = (int*)malloc(sizeof(int)*(n+1));
    for (i=1; i<=n; i++)
    {
        std::cin >> send[i];
        temp[i] = 0;
    }
    for (i=1; i<=n; i++)
    {
        k = 0;
        j = i;
        if (temp[i] == 1)
        {
            continue;
        }
        do
        {
            temp[j] = 1;
            j = send[j];
            k++;
        }
        while (j != i);
        if (k > max)
        {
            max = k;
        }
    }
    std::cout << max << "\n";

    return 0;
}