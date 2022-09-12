 #include <iostream>
 #include <algorithm>

 int *arr;
 int *dp;
 int result;

// int dynamic(int k);

// int main()
// {
//     int n;
//     std::cin >> n;
//     arr = new int[n];
//     dp = new int[n];

//     for(int i = 0; i < n; i++)
//     {
//         dp[i] = INT16_MAX;
//     }

//     int temp;
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> temp;
//         arr[i] = temp;
//     }
//     dp[0] = arr[0];
//     result = arr[0];
//     dynamic(n-1);
//     std::cout << result;
//     return 0;
// }

// int dynamic(int k)
// {
//     if(dp[k] == INT16_MAX)
//     {
//         dp[k] = std::max(dynamic(k-1)+arr[k], arr[k]);
//         result = std::max(dp[k],result);
//     }
//     return dp[k];
// }

int main()
{
    int n;
    std::cin >> n;
    arr = new int[n];
    dp = new int[n];

    int temp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        arr[i] = temp;
        dp[i] = 0;
    }

    dp[0] = arr[0];
    result = arr[0];

    for(int i = 1; i < n; i ++)
    {
        dp[i] = std::max(dp[i-1] + arr[i] , arr[i]);
        result = std::max(dp[i], result);
    }

    std::cout << result;

    return 0;
}