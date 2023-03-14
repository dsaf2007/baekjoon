#include <iostream>

int n;
int dp[1001];
int card[1001];

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {   
        cin >> card[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i] = std::max(dp[i], dp[i-j] + card[j]);
        }
    }

    std::cout << dp[n] << "\n";

    return 0;
}