#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


class Fish
{
public:
    Fish(){};

    Fish(int x, int y, int size)
    {
        this-> x = x;
        this-> y = y;
        this->size = size;
    };
    int x;
    int y;
    int size;
};

int map[22][22];
int visited[22][22];
int N;
int t;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int sizeup;

std::vector<Fish> fish_arr;
Fish shark;

bool eat = false;

bool compare(std::pair<std::pair<int, int>, int> a, std::pair<std::pair<int, int>, int> b)
{
    if(a.second == b.second)
    {
        if(a.first.first == b.first.first)
        {
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }
    return a.second < b.second;
}


void bfs(int x_pos, int y_pos)
{
    //시작위치 == 상어의 위치;
    std::queue<std::pair<std::pair<int, int>, int>>  q;
    q.push(std::pair{std::pair{shark.x, shark.y},0});
    int temp_time = 0;
    std::vector<std::pair<std::pair<int, int>, int>> result;
    while(!q.empty())
    {
        std::pair<std::pair<int, int>, int> inq = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = inq.first.first + dx[i];
            int ny = inq.first.second + dy[i];
            int cnt = inq.second;

            if(nx >= 0 && ny >=0 && nx < N && ny < N && visited[nx][ny] == 0)
            {
                if(shark.size >= map[nx][ny]) //먹거나 이동 가능
                {
                    visited[nx][ny] = 1;
                    if(map[nx][ny] > 0 && shark.size > map[nx][ny])
                    {
                        eat = true;
                        temp_time = cnt + 1;
                        result.push_back(std::pair{std::pair{nx, ny}, temp_time});
                    }
                    else
                    {
                        q.push(std::pair{std::pair{nx,ny},cnt + 1});
                    }
                }
            }
        }
    }
    if(result.size() > 0)
    {
        std::sort(result.begin(), result.end(), compare);

        t += result[0].second;
        shark.x = result[0].first.first;
        shark.y = result[0].first.second;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;


    for(int i = 0; i < N; i++) //초기화
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> map[i][j];
            /*if(map[i][j] > 0 && map[i][j] < 9)
            {
                fish_arr.push_back(Fish{i, j, map[i][j]});
            }*/
            if(map[i][j] == 9)
            {
                map[i][j] = 0;
                shark.x = i;
                shark.y = j;
                shark.size = 2;
            }
        }
    }


    while(1)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                visited[i][j] = 0;
            }
        }
        bfs(shark.x, shark.y);
        if(eat)
        {
            eat = false;
            sizeup ++;
            map[shark.x][shark.y] = 0;
            if(sizeup == shark.size)
            {
                shark.size += 1;
                sizeup =0;
            }
        }
        else{
            break;
        }

    }

    std::cout << t << "\n";

    return 0;
}