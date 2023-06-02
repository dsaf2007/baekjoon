/*
목적 : 최대 점수를 받을 수 있는 계단 오르는 방법

조건
1. 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
3. 마지막 도착 계단은 반드시 밟아야 한다.
계단 개수 300이하
각 계단별 점수 10000이하
*/
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int stairs[300]; //계단별 점수
int dp[300]; // 각 계단까지의 최대값

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> stairs[i];
    }
    dp[0] = stairs[0];
    dp[1] = dp[0] + stairs[1];
    dp[2] = max(dp[0] + stairs[2], stairs[1] + stairs[2]);

    for(int i = 3; i < N; i++)
    {
        dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i]);
    }

    cout << dp[N-1];

    return 0;
}