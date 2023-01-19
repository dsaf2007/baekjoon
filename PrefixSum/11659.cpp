#include <iostream>

int n, m;
int arr[100000];
int sum[100000];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    sum[0] = arr[0];
    for(int i = 1; i < n; i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << sum[b-1] - sum[a-2] << "\n";
    }

    return 0;
}