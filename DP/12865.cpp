#include <iostream>

int n, k;
int w[101];
int v[101];
int dp[101][100001];


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);


    //입출력
    std::cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = std::max(dp[i][j - w[j]] + v[i], dp[i][j]);
        }
    }

    std::cout << dp[n][k];




    return 0;
}