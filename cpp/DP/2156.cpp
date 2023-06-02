#include <iostream>
#include <algorithm>

int n;
int arr[10001];
int dp[10001];


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = std::max((arr[2]+arr[3]), (arr[1] + arr[3]));
    dp[3] = std::max(dp[3], dp[2]);

    for(int i = 4; i <= n; i ++)
    {
        dp[i] = std::max((dp[i-3] + arr[i-1] + arr[i]), (dp[i-2] + arr[i]));
        dp[i] = std::max(dp[i], dp[i-1]);
    }
    std::cout << dp[n];
    return 0;
}