#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m, r;
std::vector<int> graph[100001];
int result[100001];
int visited[100001];

int count;

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
            if(visited[graph[inq][i]] == 0)
            {
                visited[graph[inq][i]] = 1;
                result[graph[inq][i]] = ++count;
                q.push(graph[inq][i]);
            }
            
        }
    }
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    std::cin >> n >> m >> r;
    
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    for(int i = 1; i <=n; i++)
    {
        std::cout << result[i] << '\n';
    }
	
	return 0;
}
