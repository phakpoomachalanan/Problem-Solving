#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int times, n, i, j;
    int x, y, z;
    int drops;
    string sen;

    cin >> times;
    for (i=0; i<times; i++)
    {
        cin >> sen;
        n = sen.length();
        drops = n;
        for (j=0; j<n; j++) {
            x = min((int)sen[j]-'A', 'Z'-sen[j]+1);
            y = min((int)sen[(j+1)%n]-'A', 'Z'-sen[(j+1)%n]+1);
            z = min((int)sen[(j+2)%n]-'A', 'Z'-sen[(j+2)%n]+1);
            drops += min(x+y+z, 2*x+y);
        }
        cout << drops << '\n';
    }
    return 0;
}
