#include <iostream>
#include <vector>

long dp[100][10];

//쉬운 계단수 문제
int main()
{
    int N;
    std::cin >> N;

    for(int i = 1; i < 10; i++)
    {
        dp[0][i] = 1;
    }
    
    for(int i = 1; i < N; i++)
    {
        dp[i][0] = dp[i-1][1] % 1000000000;
        for(int j = 1; j <9; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8] % 1000000000;
        
    }

    long sum =0;
    for(int i =0; i < 10; i++)
    {
        sum += dp[N-1][i];
    }

    std::cout << sum % 1000000000;

    return 0;
}