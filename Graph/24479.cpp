#include <iostream>
#include <vector>
#include <algorithm>

int N;
int M;
int root;
int count;

std::vector<int> graph[100001];
int visited[100001];
int result[100001];

void dfs(int root)
{
    if (visited[root] == 1)
    {
        return; // 이미 방문을 한 곳일 경우 return
    }

    visited[root] = 1;
    count++;
    result[root] = count;

    for (int i = 0; i < graph[root].size(); i++)
    {
        dfs(graph[root][i]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    std::cin >> M;
    std::cin >> root;

    for (int i = 1; i <= M; i++)
    {
        int first, second;
        std::cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first); // 간선 연결
    }

    for (int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }
    dfs(root);

    for (int i = 1; i <= N; i++)
    {
        std::cout << result[i] << "\n";
    }

    return 0;
}