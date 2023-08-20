#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int map[102][102];
int visited[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> result;
int M, N, K;
int area_size;

void dfs(int x, int y)
{
    if(y < 0 || y >=  M || x < 0 || x >= N) return;
    if(visited[y][x] == 1) return;
    if(map[y][x] == 0)
    {
        visited[y][x] = 1;
        area_size++;
        for(int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            dfs(nx, ny);
        }    
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> K;

    for(int k = 0; k < K; k++) //init
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; y++)
        {
            for(int x = x1; x < x2; x++)
            {
                map[y][x] = 1;
            }
        }
    }

    for(int y = 0; y < M; y++)
    {
        for(int x = 0; x < N; x++)
        {
            area_size = 0;
            if(visited[y][x] == 1) continue;
            if(map[y][x] == 1) continue;

            dfs(x, y);
            result.push_back(area_size);
        }
    }

    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for(auto r : result)
    {
        cout << r << " ";
    }
    return 0;
}