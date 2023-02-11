#include <iostream>
#include <algorithm>

int n;
int dp[500][500];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            std::cin >> dp[i][j];
        }
    }

    for(int i = n -1; i >=0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i-1][j] += std::max(dp[i][j], dp[i][j+1]);
        }
    }

    std::cout << dp[0][0];


    return 0;
}