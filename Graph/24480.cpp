#include <iostream>
#include <vector>
#include <algorithm>

int N;
int M;
int root;

std::vector<int> graph[100001];
int visited[100001];
int result[100001];
int cnt;

void dfs(int root)
{
    if(visited[root] == 1) //방문한경우
    {
       return;
    }
    visited[root] = 1;
    result[root] = ++cnt;
    for(int i = 0; i < graph[root].size(); i++)
    {
        dfs(graph[root][i]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> root;
    for(int i = 1; i <= M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end(), std::greater<>());
    }

    dfs(root);

    for(int i = 1; i <= N; i++)
    {
        std::cout << result[i] << "\n";
    }
    return 0;
}