#include <iostream>
#include <algorithm>

int arr[1000];
int dp_l[1000];
int dp_r[1000];
int result[1000];
int n;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp_l[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            if ((arr[j] < arr[i]) && (dp_l[i] < dp_l[j] + 1))
            {
                dp_l[i] = dp_l[j] + 1;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        dp_r[i] = 1;
        for (int j = n - 1; j >= i; j--)
        {
            if ((arr[i] > arr[j]) && (dp_r[i] < dp_r[j] + 1))
            {
                dp_r[i] = dp_r[j] + 1;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        result[i] = dp_l[i] + dp_r[i] - 1;
    }

    int answer = *std::max_element(result, result + n);

    std::cout << answer;
    return 0;
}