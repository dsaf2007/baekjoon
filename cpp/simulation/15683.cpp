#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int room[9][9];
int camera[9];
int visited[9];
int cam;

int min_num = 65;

int dx[4] = {1, 0, -1, 0}; //하, 상, 우, 좌 (2번 유형 카메라 때문에 해당 형태로 배치)
int dy[4] = {0, 1, 0, -1};


bool canSee(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= M || room[x][y] == 6)
        return false;
    return true;
}

int count(int room_[][9])
{
    int total = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            //cout << room_[i][j] << " ";
            if(room_[i][j] == 0)
            {
                total++;
            }
        }//cout << "\n";
    }
    return total;
}

void calc(int x, int y, int dir, int tempMap[][9])
{
    int nx, ny;
    nx = x + dx[dir];
    ny = y + dy[dir];
    while(canSee(nx, ny))
    {
        if(tempMap[nx][ny] == 0) 
            tempMap[nx][ny] = -1;
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }
}

int watch()
{
    int total = 0;
    int tempMap[9][9];
    int cam_num = 0;
    int dir = 0, nx, ny;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            tempMap[i][j] = room[i][j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(room[i][j] > 0 && room[i][j] <6) //복사한 지도에 표시
            {
                int type = room[i][j];
                dir = camera[cam_num++];
                if(type == 1)
                {
                    calc(i, j, dir, tempMap);
                }
                else if(type == 2)
                {
                    calc(i, j, dir, tempMap);
                    calc(i, j, (dir+2)%4, tempMap);
                }
                else if(type == 3)
                {
                    calc(i, j, dir, tempMap);
                    calc(i, j, (dir+1)%4, tempMap);
                }
                else if(type == 4)
                {
                    calc(i, j, dir, tempMap);
                    calc(i, j, (dir+1)%4, tempMap);
                    calc(i, j, (dir+2)%4, tempMap);
                }
                else
                {
                    calc(i, j, dir, tempMap);
                    calc(i, j, (dir+1)%4, tempMap);
                    calc(i, j, (dir+2)%4, tempMap);
                    calc(i, j, (dir+3)%4, tempMap);
                }
            }
        }
    }

    total = count(tempMap);

    return total;
}

void dfs(int k)
{
    if(k == cam )
    {
        int temp = watch();
        min_num = min(temp, min_num);
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        camera[k] = i;
        dfs(k+1);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> room[i][j];
            if(room[i][j] > 0 && room[i][j] < 6)
            {
                cam++;
            }
        }
    }

    dfs(0);

    cout << min_num;
    return 0;
}