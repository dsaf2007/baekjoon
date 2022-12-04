#include <iostream>
#include <algorithm>

int dp[10001];
int arr[10001];
int n;

int main()
{
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = dp[0] + arr[1];
    dp[2] = std::max((arr[1] + arr[2]), (dp[0] + arr[2]));
    dp[2] = std::max(dp[1], dp[2]);

    //인덱스를 1부터 시작하는 편이 좋아보임. 헷갈릴 수 있으나 더 나은듯
    for(int i = 3; i < n; i++)
    {
        dp[i] = std::max((dp[i-3] + arr[i-1] + arr[i]), (dp[i-2] + arr[i]));
        dp[i] = std::max(dp[i], dp[i-1]);
    }

    std::cout << dp[n-1];
    return 0;
}