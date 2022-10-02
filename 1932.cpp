#include <iostream>
#include <algorithm>


int n;
int dp[501][501];
int result;
int solve();

int main()
{
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            std::cin >> dp[i][j];
        }
    }
    std::cout <<solve();

    return 0;
}

int solve()
{

    for(int i = n-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i-1][j] += std::max(dp[i][j],dp[i][j+1]);
        }
    }

    result = dp[0][0];
    return result;
}