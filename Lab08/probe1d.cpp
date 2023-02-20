#include "probelib.h"
#include <iostream>

using namespace std;

int probe_search(int left, int right);

int main(void)
{
    int n = probe_init();

    probe_answer(probe_search(0, n-1));

    return 0;
}

int probe_search(int left, int right)
{
    int mid;

    if (left == right)
    {
        return left;
    }

    mid = left + (right-left)/2;

    if (probe_check(left, mid))
    {
        return probe_search(left, mid);
    }
    return probe_search(mid+1, right);
}