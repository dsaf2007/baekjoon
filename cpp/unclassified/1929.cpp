#include <iostream>

int prime[1000001];

int main()
{

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int M, N;
    std::cin >> M >> N;

    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i <= N / 2; i++)
    {
        for (int j = 2 * i; j <= N; j += i)
        {
            if (prime[j] == 0)
                prime[j] = 1;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (prime[i] == 0)
            std::cout << i << "\n";
    }

    return 0;
}