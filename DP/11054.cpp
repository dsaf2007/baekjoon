#include <iostream>
#include <algorithm>

int arr[1000];
int dp[1000];
int n;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    int max_idx = std::max_element(arr, arr+n) - arr;
    int max = 0;
    std::cout << max_idx << "\n";
    bool is_max = true; 
    int idx = 0;
    while(is_max)
    {
        int temp = *std::max_element(arr+idx+1, arr+n);
        if(temp != max)
        {
            is_max = false;
            break;
        }
        int max_index = std::max_element(arr, arr + n) - arr;
        idx = max_index;


        int length = 1;
        int min = std::min_element(arr, arr+idx) - arr;
        int temp_min = arr[min];
        for(int i = min; i < idx; i++)
        {
            if(arr[i] > temp_min)
            {
                temp_min = arr[i];
                length++;
            }
        }

        min = std::min_element(arr+idx, arr+n) - (arr + idx);
        temp_min = arr[min];
        for(int i = n; i > idx; i--)
        {
            if(arr[i] > temp_min)
            {
                temp_min = arr[i];
                length++;
            }
        }
        dp[idx] = length;
    }
    int result = *std::max_element(dp, dp+n);
    std::cout << result << "\n";

    return 0;
}