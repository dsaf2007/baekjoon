#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, x, y;

vector<int> dp;
vector<int> m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
for(int t = 0; t < T; t++)//테스트 케이스 만큼 반복
{
    cin >> x >> y;
    dp.clear();
    m.clear();
    dp = vector<int>(y, INT32_MAX);
    m = vector<int>(y);
    
    if(x - 1 > 0)
    {
        dp[x - 1] = 0;
        m[x-1] = 0;
    }
    
    dp[x] = 1;
    m[x] = 1;
    for(int i = x; i < y - 1; i++)
    {
        if(i + m[i] + 1 > y -1  || i + m[i] > y - 1|| i + m[i] - 1 > y -1) continue;

        dp[i + m[i] + 1] = min(dp[i + m[i] +1], dp[i] + 1);
        if(dp[i + m[i] +1] >= dp[i] + 1)
        {
            if(m[i + m[i] + 1] >= m[i] + 1)
                m[i + m[i] + 1] = m[i] + 1;
        }
        dp[i + m[i]] = min(dp[i + m[i]], dp[i] +1);
        if(dp[i + m[i]]>= dp[i] +1)
        {
            if(m[i + m[i] + 1] >= m[i] + 1)
                m[i + m[i]] = m[i] + 1;
        }
        if(i + m[i] - 1 < 0) continue;
        dp[i + m[i] -1] = min(dp[i + m[i] -1], dp[i] + 1); 
        if(dp[i + m[i] -1]>= dp[i] +1)
        {
            if(m[i + m[i] - 1] >= m[i] + 1)
                m[i + m[i] - 1] = m[i] + 1;
        }
    }

    cout << dp[y - 2] + 1 << "\n";

}

    return 0;
}