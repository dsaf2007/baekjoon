#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int M;
int V;

std::vector<int> graph[10001];
int visited_dfs[10001];
int visited_bfs[10001];
std::vector<int> dfs_path;
std::vector<int> bfs_path;

void dfs(int v)
{
    if (visited_dfs[v] == 1)
    {
        return;
    }
    visited_dfs[v] = 1;
    dfs_path.push_back(v);

    for (int i = 0; i < graph[v].size(); i++)
    {
        dfs(graph[v][i]); // 가장 작은 정점번만 방문.
    }
}

void bfs(int v)
{
    std::queue<int> q;
    q.push(v);
    bfs_path.push_back(v);
    visited_bfs[v] = 1;

    while (!q.empty())
    {
        int inq = q.front();
        q.pop();

        for (int i = 0; i < graph[inq].size(); i++)
        {
            int temp = graph[inq][i];
            if (visited_bfs[temp] == 0)
            {
                visited_bfs[temp] = 1;
                bfs_path.push_back(temp);
                q.push(temp);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M >> V;

    for (int i = 1; i <= M; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }
    dfs(V);
    bfs(V);
    for (auto a : dfs_path)
    {
        std::cout << a << " ";
    }
    std::cout << "\n";
    for (auto b : bfs_path)
    {
        std::cout << b << " ";
    }
    std::cout << "\n";
    return 0;
}