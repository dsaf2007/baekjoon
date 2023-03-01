#include <iostream>
#include <algorithm>

int bag[101][100001]; // 순번, 무게
int w[101];
int v[101];

int n, k;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        std::cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            bag[i][j] = bag[i-1][j];
            if( j >= w[i]) // 배낭에 넣을 수 있을 때
            {
                bag[i][j] = std::max(bag[i][j], bag[i-1][j-w[i]] + v[i]);
            }
        }
    }
    std::cout << bag[n][k];
    return 0;
}