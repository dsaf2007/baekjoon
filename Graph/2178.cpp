#include <iostream>
#include <vector>
#include <queue>

//최단거리는 BFS로 풀이

int maze[101][101];
int visited[101][101];
int dist[101][101];
int N;
int M;

int x_dir[4] = {-1, 1, 0 , 0};
int y_dir[4] = {0, 0, 1, -1};
void bfs(int x, int y)
{
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x,y));
    dist[x][y]++;

    while(!q.empty())
    {
        int inq_x = q.front().first;
        int inq_y = q.front().second;

        q.pop();

        //인접 좌표 탐색
        for(int i = 0; i < 4; i++)
        {
            int x_move = inq_x + x_dir[i];
            int y_move = inq_y + y_dir[i];

            if(x < 0 || y < 0 || x >= N || y >= M)
            {
                continue;
            }
            if(maze[x_move][y_move] == 0)
            {
                continue;
            }
            if(visited[x_move][y_move] == 1)
            {
                continue;
            }
            visited[x_move][y_move] = 1;
            q.push(std::make_pair(x_move, y_move));
            dist[x_move][y_move] = dist[inq_x][inq_y] + 1;
        }

    }
}
int main()
{
    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::string temp;
        std::cin >> temp;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = temp[j] - '0';
        }
    }
    bfs(0,0);
    std::cout << dist[N-1][M-1];
    return 0;
}