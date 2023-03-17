#include <iostream>
#include <algorithm>

int t[16];
int p[16];
int dp[16];
int n;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> t[i] >> p[i];
    }

    int mpay=0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = std::max(dp[i], dp[i-1]);
        if(i + t[i] <= n+1) 
        {
            dp[i+t[i]] = std::max(dp[i+t[i]], dp[i] + p[i]);
        }
    }

    std::cout << *std::max_element(dp, dp+n+2);
    return 0;
}