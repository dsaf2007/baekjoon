/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 19236                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dsaf2007 <boj.kr/u/dsaf2007>                +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/19236                          #+#        #+#      #+#    */
/*   Solved: 2023/10/24 23:18:57 by dsaf2007      ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
class Fish
{
public:
    int num, dir, x, y, alive;
    Fish(){}
    Fish(int num,int dir,int x,int y,int alive)
    {
        this->num = num;
        this->dir = dir;
        this->x = x;
        this->y = y;
        this->alive = alive;
    }
};
Fish fish_list[17];
int map[4][4];
int result;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

void moveFish(int x, int y, Fish fish_list_[], int map_[][4])
{
    for(int f = 0; f < 17; f++)
    {
        if(fish_list_[f].alive == 0)
        {
            continue;
        }

        int cx = fish_list_[f].x;
        int cy = fish_list_[f].y;
        int cdir = fish_list_[f].dir;

        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];
        int dir = cdir;
        
        bool can_move = true;
        while((nx < 0 || nx >=4 || ny < 0 || ny >=4) || (nx == x && ny == y))
        {
            dir = (dir + 1) % 8;
            if(dir == cdir)
            {
                can_move = false;
            }
            nx = fish_list_[f].x + dx[dir];
            ny = fish_list_[f].y + dy[dir];
        }

        if(!can_move) continue;

        if(map_[nx][ny] != 0)
        {
            int target = map_[nx][ny];

            fish_list_[target].x = cx;
            fish_list_[target].y = cy;

            fish_list_[f].x = nx;
            fish_list_[f].y = ny;
            fish_list_[f].dir = dir;

            map_[nx][ny] = f;
            map_[cx][cy] = target;
        }
        else
        {
            fish_list_[f].x = nx;
            fish_list_[f].y = ny;
            fish_list_[f].dir = dir;
            map_[cx][cy] = 0;
            map_[nx][ny] = f;
        }
    }
}

     

void dfs(int x, int y, int map_[][4], Fish fish_list_[], int score)
{
    int temp_map[4][4];
    Fish temp_fish_list[17];

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            temp_map[i][j] = map_[i][j];
        }
    }

    for(int i = 0; i < 17; i++)
    {
        temp_fish_list[i] = fish_list_[i];
    }

    int target_fish = temp_map[x][y];
    int dir = temp_fish_list[target_fish].dir;
    temp_fish_list[target_fish].alive = 0;
    temp_map[x][y] = 0;

    score += target_fish;
    if(score > result)
    {
        result = score;
    }

    moveFish(x,y,temp_fish_list, temp_map);

    for(int i = 1; i <= 3; i++)
    {
        int nx = x + dx[dir]*i;
        int ny = y + dy[dir]*i;

        if(nx < 0 || ny < 0 || nx >=4 || ny >= 4)
        {
            break;
        }
        
        if(temp_map[nx][ny] > 0)
        {
            dfs(nx, ny, temp_map, temp_fish_list, score);
        }
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            std::cin >> a >> b;
            map[i][j] = a;
            fish_list[a] = Fish{a,b - 1,i,j,1};
        }
    }

    dfs(0,0,map,fish_list,0);

    std::cout << result << "\n";

    return 0;
}