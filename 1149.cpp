#include <iostream>
#include <algorithm>

int dp[1001][3];
int result;
int n;

int solve();

int main()
{

    std::cin >> n;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> dp[i][j];
        }
    }
    std::cout << solve();

    
    return 0;
}

int solve()
{
    for(int i = 1; i < n; i++)
    {
        dp[i][0] += std::min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] += std::min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] += std::min(dp[i-1][1],dp[i-1][0]);
    }

    result = std::min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    
    return result;
}