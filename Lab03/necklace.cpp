#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int n, i, head, tail;
    list<int>* lace;
    list<int>::iterator itr;

    cin >> n;
    lace = (list<int>*)malloc(sizeof(list<int>)*n);

    for (i=0; i<n; i++)
    {
        lace[i].push_back(i+1);
    }
    for (i=0; i<n-1; i++)
    {
        cin >> head, tail;
        itr = find(lace[0].begin(), lace[0].end(), tail);
    }

    return 0;
}