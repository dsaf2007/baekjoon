#include <iostream>
#include <vector>

int dp[31][31];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 0;


    for(int i = 0; i <= 30; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    std::cin >> t;
    std::vector<int> result;

    for(int i = 0; i < t; i++)
    {
        int n, m;
        std::cin >> n >> m;

       result.push_back(dp[m][n]);
    }

    for(auto a : result)
    {
        std::cout << a << "\n";
    }

    return 0;
}