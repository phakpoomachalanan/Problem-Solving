#include <iostream>

int main(void)
{
    int  n, k, t, check=0;
    int* path;

    std::cin >> n >> k >> t;
    path = (int*)malloc(sizeof(int)*n);
    for (int i=0; i<n; i++)
    {
        path[i] = 0;
    }
    for (int i=0; i<n; i=(i+k)%n)
    {
        if (i == t-1)
        {       
            check++;
            break;
        }
        if (path[i] == 1)
        {
            break;
        }
        path[i] = 1;
        check++;
    }
    std::cout << check << "\n";

    return 0;
}