#include <iostream>

using namespace std;

const int MAX_N = 20;

int n, s;
int temp[MAX_N];
int num_list[MAX_N];

void get_input();
void rotate();
void fill();
void print_output();

int main()
{
    get_input();
    rotate();
    fill();
    print_output();

    return 0;
}

void get_input()
{
    int i;

    cin >> n >> s;

    for (i=0; i<n; i++)
    {
        cin >> num_list[i];
    }
    for (i=n; i<MAX_N; i++)
    {
        num_list[i] = i - n + 1;
    }
    
    return;
}

void rotate()
{
    int i, j;

    for (i=MAX_N-s, j=0; i<MAX_N; i++, j++)
    {
        temp[j] = num_list[i];
    }
    for (i=0; i<MAX_N-s; i++, j++)
    {
        temp[j] = num_list[i];
    }
}

void fill()
{
    int i, j;

    for (i=0; i<5; i++)
    {
        for (j=0; j<4; j++)
        {
            num_list[4*i+j] = temp[5*j+i];
        }
    }
}

void print_output()
{
    int i;

    for (i=0; i<MAX_N; i++)
    {
        cout << num_list[i] << endl;
    }
}