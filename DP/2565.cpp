#include <iostream>
#include <vector>
#include <algorithm>


int n;
std::vector<std::pair<int, int>> line;
int dp[501];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i =0; i < n; i++)
    {
        int a,b;
        std::cin >> a >> b;
        line.push_back(std::pair<int, int>(a,b));
    }
    std::sort(line.begin(), line.end());

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(line[i].second < line[j].second && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = *std::max_element(dp, dp+ 500);

    std::cout << n - max;
    return 0;
}

