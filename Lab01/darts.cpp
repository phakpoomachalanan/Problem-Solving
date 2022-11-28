#include <iostream>

int main(void)
{
    int times, x, y, score=0;
    float rSquare;

    std::cin >> times;
    for (int i=0; i<times; i++)
    {
        std::cin >> x >> y;

        rSquare = x*x + y*y;

        if (rSquare > 100)
        {
            score += 0;
        }
        else if (rSquare <= 4)
        {
            score += 5;
        }
        else if (rSquare <= 16)
        {
            score += 4;
        }
        else if (rSquare <= 36)
        {
            score += 3;
        }
        else if (rSquare <= 64)
        {
            score += 2;
        }
        else if (rSquare <= 100)
        {
            score += 1;
        }
    }
    std::cout << score << "\n";

    return 0;
}
