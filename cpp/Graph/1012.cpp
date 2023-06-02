#include <iostream>

int t, n , m, k;
int graph[51][51];
int visited[51][51];

void init()
{
    for(int i = 0; i < 51; i++)
    {
        for(int j = 0; j < 51; j++)
        {
            graph[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int dfs(int x, int y)
{
    if(graph[x][y] == 1 && visited[x][y] == 0 &&
    x >= 0 && x <= 50 && y >=0 && y <= 50)
    {
        visited[x][y] = 1;
        dfs(x + 1, y);
        dfs(x -1 , y);
        dfs(x, y + 1);
        dfs(x, y - 1);

        return 1;
    }
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    std::cin >> t;

    for(int tk = 0; tk < t; tk++)
    {
        init();
        std::cin >> m >> n >> k; //가로 세로 배추
        for(int i = 0; i < k; i++)
        {
            int x, y;
            std::cin >> x >> y;
            graph[x][y] = 1;
        }
        int count = 0;
        for(int i = 0; i <= m; i++)
        {
            for(int j = 0; j <=n; j++)
            {
                if(dfs(i,j) == 1)
                {
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}