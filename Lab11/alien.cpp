#include <iostream>

using namespace std;

const int MAX_N = 100001;

struct Nisit
{
    int x, y;
};

int n;
int ali_x, ali_y;
int radius_square;
int caught = 0;
Nisit nisit[MAX_N];

void get_input();
void cal();
int get_distance(int x, int y);

int main()
{
    get_input();
    cal();

    cout << caught << '\n';

    return 0;
}

void get_input()
{
    int i, r;

    cin >> n >> ali_x >> ali_y >> r;

    for (i=0; i<n ;i++)
    {
        cin >> nisit[i].x >> nisit[i].y;
    }

    radius_square = r*r;

    return;
}

void cal()
{
    int i;

    for (i=0; i<n; i++)
    {
        if (radius_square >= get_distance(nisit[i].x, nisit[i].y))
        {
            caught++;
        }
    }

    return;
}

int get_distance(int x, int y)
{
    int dx = ali_x-x;
    int dy = ali_y-y;

    return dx*dx + dy*dy;
}