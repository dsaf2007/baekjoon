#include <iostream>

int bag[5001] = {
    [0 ... 5000] = -1
};
int N;

void temp()
{
    N = 2;
    bag[N] = 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;
    std::cout << N << std::endl;
    temp();
    std::cout << N << std::endl;

    bag[3] = 1;
    bag[5] = 1;
    bag[6] = 2;

    for (int i = 8; i <= N; i++)
    {
        bag[i] = std::min(bag[i - 3] + 1, bag[i - 5] + 1);
    }

    if (bag[N] == 5001)
    {
        std::cout << "-1";
    }
    else
    {
        std::cout << bag[N] << "\n";
    }

    return 0;
}