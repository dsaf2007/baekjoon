#include <iostream>

int N; // 세로
int M; // 가로
int K;
int T;

int ground[50][50];
int visited[50][50];
int count;
int size;

void init()
{
    count = 0;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            ground[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
void bfs(int x, int y)
{
    if (visited[y][x] == 1)
    {
        return;
    }
    if (ground[y][x] == 0)
    {
        return;
    }
    if (x < 0 || y < 0 || x >= M || y >= N)
    {
        return;
    }

    visited[y][x] = 1;
    size++;

    // std::cout << "visit x : " << x << " , y : " << y <<std::endl;
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x - 1, y);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for (int p = 0; p < T; p++)
    {
        std::cin >> M >> N >> K;
        for (int k = 0; k < K; k++)
        {
            int x, y;
            std::cin >> x >> y;

            ground[y][x] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                size = 0;
                bfs(j, i);
                if (size > 0)
                {
                    count++;
                }
            }
        }
        std::cout << count << "\n";
        init();
    }
    return 0;
}