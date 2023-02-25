#include <iostream>
#include <vector>
#include <algorithm>

int n, k;

int dp[101][100001];
int w[101];
int v[101];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        int weight, value;
        std::cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if( j >= w[i])
            {
                dp[i][j] = std::max((dp[i-1][j]), (dp[i-1][j-w[i]] + v[i]));
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    std::cout << dp[n][k];

    return 0;
}