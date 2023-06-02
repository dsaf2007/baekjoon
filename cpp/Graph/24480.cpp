#include <iostream>
#include <vector>
#include <algorithm>

int n,m,r;
std::vector<int> graph[100001];
int result[100001];
int visited[100001];
int count;


void dfs(int root)
{
    if(visited[root] != 1)
    {
        visited[root] = 1;
        count++;
        result[root] = count;

        for(int i = 0; i < graph[root].size(); i++)
        {
            dfs(graph[root][i]);
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> r;

    for(int i = 1; i <=m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        std::sort(graph[i].begin(),graph[i].end(), std::greater<>());
    }

    dfs(r);

    for(int i = 1; i <= n; i++)
    {
        std::cout << result[i] << "\n";
    }

    return 0;
}