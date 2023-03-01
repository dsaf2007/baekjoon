#include <iostream>

int n;
int bag[5001];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for (int i = 0; i <= 5000; i++)
    {
        bag[i] = 5001;
    }

    bag[3] = 1;
    bag[5] = 1;
    bag[6] = 2;

    for (int i = 8; i <= n; i++)
    {
        bag[i] = std::min(bag[i - 3], bag[i - 5]) + 1;
    }

    if (bag[n] == 5001)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << bag[n];
    }

    return 0;
}