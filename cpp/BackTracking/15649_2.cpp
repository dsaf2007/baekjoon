#include <iostream>

int n, m;
int arr[8];
int visited[9];
void dfs(int k)
{
    if(k == m)
    {
        for(int i = 0; i < m; i++)
        {
            std::cout << arr[i] << " ";
        }std::cout << "\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                arr[k] = i;
                dfs(k + 1);
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;

    dfs(0);

    return 0;
}