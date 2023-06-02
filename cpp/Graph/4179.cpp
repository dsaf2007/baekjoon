#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char map[1001][1001];
int dist1[1001][1001]; //불
int dist2[1001][1001];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int result;
void bfs_fire(std::vector<pair<int, int>> v)
{
    queue<pair<int, int>> q;

    for(auto a : v)
    {
        q.push(a);
    }
    
    while(!q.empty())
    {
        pair<int, int> inq = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = inq.first + dr[i];
            int nc = inq.second + dc[i];

            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(dist1[nr][nc] >= 0 || map[nr][nc] == '#') continue;
            dist1[nr][nc] = dist1[inq.first][inq.second] + 1;
            q.push({nr,nc});
        }
    }
}

void bfs_jh(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});

    while(!q.empty())
    {
        pair<int, int> inq = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = inq.first + dr[i];
            int nc = inq.second + dc[i];

            if(nr >= R || nr < 0 || nc >= C || nc < 0) //밖으로 나갔을 때
            {
                result = dist2[inq.first][inq.second] + 1;
                return;
            }
            if(dist2[nr][nc] >= 0 || map[nr][nc] == '#') continue;
            if(dist1[nr][nc] != -1 && dist1[nr][nc] <= dist2[inq.first][inq.second] + 1) continue;
            q.push({nr, nc});
            dist2[nr][nc] = dist2[inq.first][inq.second] + 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    pair<int, int> jh;
    vector<pair<int, int>> fire;

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            dist1[i][j] = -1;
            dist2[i][j] = -1;
        }
    }

    for(int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < C; j++)
        {
            map[i][j] = input[j];
            if(map[i][j] == 'J')
            {
                jh = {i,j};
                dist2[i][j] = 0;
            }
            if(map[i][j] == 'F')
            {
                pair<int, int> temp = {i,j};
                fire.push_back(temp);
                dist1[i][j] = 0;
            }
        }
    }

    bfs_fire(fire);
    bfs_jh(jh.first, jh.second);

    if(result <= 0)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << result << "\n";
    }


    return 0;
}