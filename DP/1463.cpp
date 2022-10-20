#include <iostream>
#include <algorithm>
#include <cstdlib>

int rec(int k);
int* dp;

int cnt;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    dp = new int[n];

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1000;
    }

    rec(n);

    std::cout << dp[1];

    return 0;
}

int rec(int k)
{
    if(k == 1)
    {
        dp[k] = std::min(cnt, dp[k]);
        return dp[k];
    }
    else
    {
        cnt++;
        if( k % 3  == 0)
        {
            dp[k] = std::min(rec(k/3), cnt);
            cnt--;
        }
        else if( k % 2 == 0)
        {
            dp[k] = std::min(rec(k/2), cnt);
            cnt--;
        }
        else
        {
            dp[k] = std::min(rec(k-1), cnt);
            cnt--;
        }

        std::cout << k << " " << cnt << std::endl;
        return dp[k];

    }
}