#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N;
int M;
int root;
int count;

std::vector<int> graph[100001];
int result[100001];
int visited[100001];

void bfs(int root)
{
    std::queue<int> q;
    q.push(root);
    visited[root] = 1;
    result[root] = ++count;

    while(!q.empty())
    {
        int inq = q.front();
        q.pop();
        for(int i = 0; i < graph[inq].size(); i++)
        {
            int temp = graph[inq][i];
            if(visited[temp] == 0)
            {
                visited[temp] = 1;
                result[temp] = ++count;
                q.push(temp);
            }
        }
    }
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M >> root;
    for(int i = 1; i <= M; i ++)
    {
        int a, b;
        std::cin >> a >>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= N; i++)
    {
        std::sort(graph[i].begin(), graph[i].end(), std::greater<>());
    }
    bfs(root);

    for(int i = 1; i <= N; i++)
    {
        std::cout << result[i] << "\n";
    }
    return 0;
}