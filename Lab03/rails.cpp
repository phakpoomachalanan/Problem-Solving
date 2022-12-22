#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main(void)
{
    int n, temp, flag, i, j, last;
    stack<int>   station;
    list<string> output;
    list<string>::iterator itr;

    do
    {
        cin >> n;
        while (n != 0)
        {
            flag = 1;
            last = 0;
            for (i=0; i<n; i++)
            {
                cin >> temp;
                if (temp == 0)
                {
                    break;
                }
                if (temp > last)
                {
                    for (j=last+1; j<=temp; j++)
                    {
                        station.push(j);
                    }
                    station.pop();
                }
                if (temp < last)
                {
                    if (station.top() != temp)
                    {
                        flag = 0;
                    }
                    station.pop();
                }
                if (temp > last)
                {
                    last = temp;
                }
            }
            if (temp == 0)
            {
                output.push_back("");
                break;
            }
            if (flag == 1)
            {
                output.push_back("Yes");
            }
            else if (flag == 0)
            {
                output.push_back("No");
            }
        }
    }
    while (n != 0);
    for (itr=output.begin(); itr!=output.end(); itr++)
    {
        cout << *itr << '\n';
    }

    return 0;
}