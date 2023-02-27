#include <iostream>
#include <algorithm>

const int MAX_N = 100001;

using namespace std;

int n;
int bananas[MAX_N];
int max_b[MAX_N];

void get_input();

int main(void)
{
    int* ptr = max_b;

    get_input();

    max_b[0] = 0;
    max_b[1] = 0;
    max_b[2] = bananas[2];

    for (int i=3; i<n; i++)
    {
        ptr = max_element(ptr, &max_b[i-2]);
        max_b[i] = bananas[i] + *ptr;
    }

    cout << *max_element(ptr, max_b+n) << '\n';

    return 0;
}

void get_input()
{
    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> bananas[i];
    }

    return;
}