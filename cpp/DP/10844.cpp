#include <iostream>
#include <algorithm>

int n;
long dp[100][9];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0; i < 10; i++)
    {
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][1] % 1000000000;
        for(int j = 1; j < 9; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8] % 1000000000;
    }

    long sum = 0;

    for(int i = 0; i < 10; i++)
    {
        sum += dp[n-1][i];
    }

    std::cout << sum % 1000000000;

    return 0;
}