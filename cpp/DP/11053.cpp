#include <iostream>
#include <algorithm>

int arr[1000];
int dp[1000];
int N;

int main()
{
    std::cin >> N;

    int input;
    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        arr[i] = input;
    }

    for(int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[i] < dp[j]+1) // i 인덱스 이전의 값을 탐색하면서 최대값 구함.
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int size = sizeof(dp) / sizeof(*dp);
    int max = *std::max_element(dp, dp + size); //algorithm 내장. 배열의 최대값 반환.

    std::cout << max;
    return 0;
}