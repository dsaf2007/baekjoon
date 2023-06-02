#include <iostream>

int n, k;
int arr[100000];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    std::cin >> arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        arr[i] = arr[i-1] + temp;
    }
    int sum = arr[k-1];
    int max = sum;
    for(int i = k; i < n; i++)
    {
        sum = arr[i] - arr[i-k];
        if(sum > max)
        {
            max = sum;
        }
    }
    std::cout << max << "\n";
    return 0;
}