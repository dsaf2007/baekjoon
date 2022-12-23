#include <iostream>

int T, M, N, K;
int count;
int size;

int graph[50][50];
int visited[50][50];

void init()
{
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    count = 0;
}

void dfs(int x, int y)
{
    if(visited[y][x] == 1)
    {
        return;
    }
    if(graph[y][x] == 0)
    {
        return;
    }
    if(x < 0 || x >= M || y < 0 || y >= N)
    {
        return;
    }
    dfs(x,y+1);
    dfs(x,y-1);
    dfs(x+1,y);
    dfs(x-1,y);
}
int main()
{
    std::cin >> T;

    for(int t = 0; t < T; t++)
    {
        std::cin >> M >> N >> K;

        for(int k = 0; k < K; k++)
        {
            int x, y;
            std::cin >> x >> y;
            graph[y][x] = 1;
        }

        for(int i = 0; i < N; i++)
        {
            for(int j =0; j < M; j++)
            {
                size = 0;
                dfs(j, i);
                if(size > 0)
                {
                    count ++;
                }
            }
        }
        std::cout << count << std::endl;
        init();
    }
    return 0;
}