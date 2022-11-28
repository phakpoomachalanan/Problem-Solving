#include <iostream>

int main(void)
{
    int  x=0, y=0;
    char path[101], direction;

    std::cin >> path;
    for (int i=0; path[i]!='\0'; i++)
    {
        direction = path[i];
        switch (direction)
        {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'Z':
                x = 0;
                y = 0;
        }
    }
    std::cout << x << " " << y << "\n";

    return 0;
}