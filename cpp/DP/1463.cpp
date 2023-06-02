#include <iostream>
#include <algorithm>

int dp[1000001];

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 2; i < 1000001; i++)
    {
        dp[i] = i;
    }

    for(int i = 1; i < 1000001; i++)
    {
        int temp = dp[i] + 1;

        if(i*3 <= 1000001)
            dp[i*3] = min(dp[i*3], temp);
        if(i*2 <= 1000001)
            dp[i*2] = min(dp[i*2], temp);
        
        dp[i+1] = min(dp[i+1], temp);
    }

    cout << dp[N] << "\n";
    
    return 0;
}