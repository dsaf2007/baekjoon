#include <iostream>
#include <queue>
#include <vector>

int t, l;
int board[301][301];
int visited[301][301];
int cnt[301][301];
std::pair<int, int> pos; // 출발지
std::pair<int, int> des; // 목적지

std::vector<std::pair<int, int> > move;

void init()
{
    move.clear();
    move.push_back(std::make_pair(1, 2));
    move.push_back(std::make_pair(1, -2));
    move.push_back(std::make_pair(-1, 2));
    move.push_back(std::make_pair(-1, -2));
    move.push_back(std::make_pair(2, 1));
    move.push_back(std::make_pair(2, -1));
    move.push_back(std::make_pair(-2, 1));
    move.push_back(std::make_pair(-2, -1));

    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            board[i][j] = 0;
            visited[i][j] = 0;
            cnt[i][j] = 0;
        }
    }
}

void bfs(std::pair<int, int> pos)
{
    std::queue<std::pair<int, int> > q = std::queue<std::pair<int, int> >();
    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while (!q.empty())
    {
        std::pair<int, int> inq = q.front();
        q.pop();

        if (inq.first == des.first && inq.second == des.second)
        {
            return;
        }

        for (auto m : move)
        {
            int temp_x = inq.first + m.first;
            int temp_y = inq.second + m.second;
            if(visited[temp_x][temp_y] == 1)
            {
                continue;
            }
            if (temp_x < 0 || temp_x >= l || temp_y < 0 || temp_y >= l)
            {
                continue;
            }
            visited[temp_x][temp_y] = 1;
            q.push(std::make_pair(temp_x, temp_y));
            cnt[temp_x][temp_y] = cnt[inq.first][inq.second] + 1;
        }
    }
}
int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        init();

        std::cin >> l;
        if(l == 0)
        {
            std::cout << 0 << "\n";
            continue;
        }
        std::cin >> pos.first >> pos.second;
        std::cin >> des.first >> des.second;

        bfs(pos);

        std::cout << cnt[des.first][des.second];

        if(k < t-1)
        {
            std::cout << "\n";
        }
    }

    return 0;
}