#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2000001;

int n;
vector<int> arr;

void merge(int left, int mid, int right);
void merge_sort(int left, int right);

int main(void)
{
    int i, temp;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    do
    {
        for (i=0; i<n; i++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        merge_sort(0, n-1);
        for (i=0; i<n-1; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << arr[n-1] << '\n';
        arr.clear();

        cin >> n;
    }
    while (n != 0);

    return 0;
}

void merge(int left, int mid, int right)
{
    vector<int> temp(right-left+1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    for (; i<=mid&&j<=right; k++)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i++];
        }
        else
        {
            temp[k] = arr[j++];
        }
    }
    for (; i<=mid; i++, k++)
    {
        temp[k] = arr[i];
    }
    for (; j<=right; j++, k++)
    {
        temp[k] = arr[j];
    }
    for (i=left, k=0; i<=right; i++, k++)
    {
        arr[i] = temp[k];
    }

    return;
}

void merge_sort(int left, int right)
{
    int mid;

    if (left >= right)
    {
        return;
    }

    mid = (left+right)/2;

    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);

    return;
}