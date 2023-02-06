#include <iostream>
#include <vector>
#include <algorithm>


int n;
int result;
std::vector<std::pair<int, int>> line;
int dp[500];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >>n;

    for(int i = 0; i < n; i++)
    {
        int a, b;

        std::cin >> a >> b;

        line.push_back(std::make_pair(a,b));
    }
    std::sort(line.begin(), line.end());

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(line[j].second < line[i].second && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = *std::max_element(dp, dp + 500);

    std::cout << n -max;

}