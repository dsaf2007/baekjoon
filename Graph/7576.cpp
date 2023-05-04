#include <iostream>
#include <queue>
#include <vector>


int r, c, result;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};


int map[1001][1001]; // 1 : 익은토마토, 0 : 익지 않은 토마토, -1 : 토마토 없음
int dist[1001][1001];
using namespace std;


void bfs(vector<pair<int, int>> v){
    queue<pair<int, int>> q;

    for(auto a : v)//모든 시작점에 대해 삽입.
    {
        q.push(a);
        
    }

    while(!q.empty())
    {
        pair<int, int> inq = q.front();
        q.pop();
        for(int m = 0; m < 4; m++)
        {
            int nr = inq.first + dr[m];
            int nc = inq.second + dc[m];
            if(nc >= 0 || nc < c || nr >= 0 || nr < r)
            {
                if(dist[nr][nc] >= 0) continue; //안익은 토마토일 경우
                {
                    dist[nr][nc] = dist[inq.first][inq.second] + 1;
                    q.push(pair{nr, nc});
                }   
            }
        }
    }
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(dist[i][j] == -1)
            {
                result = -1;
                return;
            }
            result = max(result, dist[i][j]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> c >> r;

    vector<pair<int, int>> start;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                start.push_back(pair{i,j});
            }
            if(map[i][j] == 0)
            {
                dist[i][j] = -1;
            }

        }
    }

    bfs(start);

    cout << result;

    return 0;
}