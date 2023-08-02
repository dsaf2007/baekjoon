#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101]; // -1 : 잠김, 0 : 방문 안함, 1 : 방문함

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int N;
int max_height;
int max_area;

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});

    while (!q.empty())
    {
        pair<int, int> inq;
        inq = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int next_r = inq.first + dr[d];
            int next_c = inq.second + dc[d];

            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N)
                continue;
            if (visited[next_r][next_c] != 0)
                continue;

            q.push({next_r, next_c});
            visited[next_r][next_c] = 1;
        }
    }
}

void init(int height)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(map[i][j] <= height) visited[i][j] = -1;
            else visited[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            max_height = max(max_height, map[i][j]);
        }
    }

    for (int h = max_height; h >= 0; h--)
    {
        int num_of_area = 0;
        init(h);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {
                    bfs(i, j);
                    num_of_area++;
                }
            }
        }
        max_area = max(num_of_area, max_area);
    }

    cout << max_area << "\n";

    return 0;
}
