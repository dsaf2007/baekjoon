#include <iostream>
#include <algorithm>

using namespace std;

int T, N;
int arr[2][1000001];
int dp[2][1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    

    for(int t = 0; t < T; t++)
    {
        cin >> N;
        for(int j = 0; j < 2; j++)
        {
            for(int n = 1; n <= N; n++)
            {
                cin >> arr[j][n];       
            }
        }

        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];

        for(int i = 2; i <= N; i++)
        {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + arr[1][i];
        }
        cout << max(dp[0][N], dp[1][N]) << "\n";
    }



    return 0;
}