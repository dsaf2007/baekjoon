#include <iostream>
#define MAX 8

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            visited[i] = true;
            arr[k] = i;
            dfs(k + 1);
            visited[i] = false;
        }
    }
}

int main()
{

    std::cin >> N >> M;
    dfs(0);
    return 0;
}
