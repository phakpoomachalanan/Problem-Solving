#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> bananas;
vector<int> max_b;

void get_input();

int main(void)
{


    get_input();

    return 0;
}

void get_input()
{
    int temp;

    cin >> n;

    for (int i=0; i<n; i++)
    {
        cin >> temp;
        bananas.push_back(temp);
    }

    return;
}