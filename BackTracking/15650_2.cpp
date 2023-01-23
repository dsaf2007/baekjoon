#include <iostream>
#include <vector>

int result[9];
bool visited[9];
int N, M;

void combination(int k, int n, int m)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                if (k != 0 && result[k - 1] > i)
                    continue; // 오름차순으로 조합을 생성하기 위해
                visited[i] = true;
                result[k] = i;
                combination(k + 1, n, m);
                visited[i] = false;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;
    combination(0, N, M);
    return 0;
}
