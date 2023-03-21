#include <iostream>
#include <vector>
//최초 풀이는 브루트포스 이용
//2트는 부분합 이용

int map[1025][1025];
int dp[1025][1025];
int N, M;
std::vector<int> result;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        
        for(int j = 1; j <= N; j++)
        {
            int input;
        std::cin >> input;
            dp[i][j] = dp[i][j-1] + input + dp[i-1][j] - dp[i-1][j-1];
        }
    }

    //1,1 부터의 x,y까지의 합





    for(int i = 0; i < M; i++)
    {
        int x1, y1, x2, y2;

        std::cin >> x1 >> y1 >> x2 >> y2;

        int temp = 0;

        temp = dp[x2][y2] - dp[x2][y1 - 1] + dp[x1-1][y1-1] - dp[x1-1][y2];
        result.push_back(temp);
    }
    for(auto a : result)
    {
        std::cout << a << "\n";
    }
    return 0;
}