#include <iostream>
#include <vector>

int n,m;
long long sum[1000001];
std::vector<int> mod_sum;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        int temp;
        std::cin >> temp;
        sum[i] = sum[i-1] + temp;

        if(sum[i] % m == 0)
        {
            mod_sum.push_back(i);
        }
    }
    return 0;
}