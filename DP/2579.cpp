#include <iostream>

int solution();

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout << solution();
    return 0;
}

int solution()
{
    int n;
    int* dp;
    int* inputArr;

    std::cin >> n;

    dp = new int[n];
    inputArr = new int[n];

    for(int i = 0; i < n; i++)
    {
        std::cin >> inputArr[i];
    }

    dp[0] = inputArr[0];
    dp[1] = dp[0] + inputArr[1];
    dp[2] = std::max(inputArr[0], inputArr[1]) + inputArr[2];

    for(int i = 3; i < n; i++)
    {
        dp[i] = std::max(inputArr[i-1]+dp[i-3], dp[i-2]) + inputArr[i];
    }

    return dp[n-1];
}