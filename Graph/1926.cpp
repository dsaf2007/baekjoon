#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;

int map[501][501];
int visited[501][501];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

using namespace std;


int bfs(int r, int c)
{
    int size = 0;
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = 1;

    while(!q.empty())
    {
        pair inq = q.front();
        q.pop();
        size++;

        for(int i = 0; i < 4; i++)
        {
            int nr = inq.first + dr[i];
            int nc = inq.second + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(map[nr][nc] == 0) continue;
            if(visited[nr][nc] == 1) continue;
            q.push({nr, nc});
            visited[nr][nc] = 1;
        }


    }

    return size;
}

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    vector<int> result;
    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visited[i][j] == 0 && map[i][j] == 1)
            {
                result.push_back(bfs(i,j));
            }
        }
    }
    
    int max = result.size() == 0 ? 0 : *max_element(result.begin(), result.end());

    cout << result.size() << "\n" << max;


    return 0;
}