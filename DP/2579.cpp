#include <iostream>
#include <algorithm>

int stair[301];
int dp[301];
int n;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> stair[i];
    }

    dp[n-1] = stair[n-1];
    dp[n-2] = dp[n-1] + stair[n-2];
    dp[n-3] = std::max(dp[n-1] + stair[n-3], dp[n-2]);

    for(int i = n - 4; i >=0; i--)
    {
        dp[i] = std::max(dp[i+3] + stair[i] + stair[i+1], dp[i+2] + stair[i]);
    }

    std::cout << dp[0];
    return 0;
}