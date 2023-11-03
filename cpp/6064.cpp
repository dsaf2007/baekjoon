#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[4001][4001];
int T, M, N, x, y;


void makeDp()
{
    int m = 0; int n = 0;
    int idx = 0;
    while(true)
    {
        dp[m][n] = idx++;

        if(m == M && n==N) break;

        if(m == M) m = 1;
        else m++;

        if(n == N) n = 1;
        else n++;
    }
}

int cal(int a, int b)
{
    int type = a < b ? 1 : 2;

    if(dp[a][b] < 1) return -1;
    return dp[a][b];
}

int main()
{
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        cin >> M >> N >> x >> y;
        memset(dp, 0, sizeof(dp));
        makeDp();
        cout << cal(x, y) << "\n";
    }
    return 0;
}