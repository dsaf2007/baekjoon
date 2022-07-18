#include <iostream>
#include <vector>
#include <cstdlib>

#define MAX 9

int arr[MAX];
bool visited[MAX];

void dfs(int k, int n, int m)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                arr[k] = i;
                dfs(k + 1, n, m);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int N, M;

    std::cin >> N >> M;

    dfs(0, N, M);
}