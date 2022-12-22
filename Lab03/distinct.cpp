#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int  n, i, j, temp;
    int* price;
    set<int> sum;

    cin >> n;
    price = (int*)malloc(sizeof(int)*n);

    for (i=0; i<n; i++)
    {
        cin >> price[i];
    }
    for (i=0; i<n; i++)
    {
        temp = 0;
        for (j=i; j<n; j++)
        {
            temp += price[j];
            sum.insert(temp);
        }
    }
    cout << sum.size() << '\n';

    return 0;
}