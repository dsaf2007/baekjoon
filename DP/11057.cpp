#include <iostream>

int dp[1001][11];
int n;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 1; i <= 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++)
    {
        dp[i][1] = 1;
        for(int j = 2; j <= 10; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 10007;
        }
    }

    int sum = 0;

    for(int i = 1; i <= 10; i++)
    {
        sum += dp[n][i];
    }

    std::cout << sum % 10007; 

    return 0;
}