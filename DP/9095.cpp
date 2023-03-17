#include <iostream>

int T, N;
int dp[12];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        std::cin >> N;

        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= N; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        std::cout << dp[N] << "\n";
    }
    return 0;
}