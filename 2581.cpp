#include <iostream>

int main()
{
    int M, N;
    std::cin >> M >> N;
    int sum = 0;
    int primemin = 10000;
    for (int i = M; i <= N; i++)
    {
        bool isprime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime == true && i != 1)
        {
            sum += i;
            if (primemin > i)
                primemin = i;
        }
    }
    if (primemin == 10000)
        std::cout << -1;
    else
    {
        std::cout << sum << std::endl;
        std::cout << primemin;
    }

    return 0;
}