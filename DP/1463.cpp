#include <iostream>
#include <algorithm>

int n;

int dp[1000001];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;


    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;

        if(i % 2 == 0)
        {
            dp[i] = std::min((dp[i/2] + 1), dp[i]);
        }
        if(i % 3 == 0)
        {
            dp[i] = std::min((dp[i/3] + 1), dp[i]);
        }
    }

    std::cout << dp[n];
    return 0;
}