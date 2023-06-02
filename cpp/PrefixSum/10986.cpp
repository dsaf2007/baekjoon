#include <iostream>
#include <vector>

int n,m;
long long sum[1000001];
long long mod[1001];


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        int temp;
        std::cin >> temp;
        sum[i] = sum[i-1] + temp;
        mod[sum[i] % m]++;
    }
    long long result = 0;
    for(int i = 0; i < m; i++)
    {
        long long temp = mod[i]*(mod[i] - 1)/2;
        result += temp;
    }
    std::cout << result + mod[0] << "\n";
    return 0;
}