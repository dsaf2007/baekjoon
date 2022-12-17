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
    if(visited_dfs[v] == 1)
    {
        return;
    }
    visited_dfs[v] = 1;
    dfs_path.push_back(v);

    dfs(graph[v][0]); // 가장 작은 정점번만 방문.
}

void bfs(int v)
{
    std::queue<int> q;
    q.push(v);

    while(!q.empty())
    {
        int inq = q.front();
        q.pop();

        int temp = graph[inq][0];
        if(visited_bfs[temp] == 0)
        {
            visited_bfs[temp] = 1;
            bfs_path.push_back(temp);
            q.push(temp);
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
    return 0;
}