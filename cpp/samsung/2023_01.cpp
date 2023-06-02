#include <iostream>
#include <vector>
#include <fstream>

int N, M, K;

class Runner
{
public:
    int r;
    int c;
    int arrived;
    int num;

    Runner() {}

    Runner(int num, int r, int c, int arrived)
    {
        this->num = num;
        this->r = r;
        this->c = c;
        this->arrived = arrived;
    }
};

std::vector<Runner> runner_list;
std::pair<int, int> Exit;

int result, total_time;

double center_r, center_c;

int map[12][12];
int temp_map[12][12];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int distance(int r, int c) //출구까지 거리
{
    return std::abs(r - Exit.first) + std::abs(c - Exit.second);
}

void printMap();

//이동
void move()
{
    for(int num = 0; num < runner_list.size(); num++)
    {
        if(runner_list[num].arrived == 1) continue;
        //현재 좌표
        int cr = runner_list[num].r;
        int cc = runner_list[num].c;
        int moved = 0;
        for(int i = 0; i < 4; i++) //상하좌우
        {
            if(moved == 1) continue;
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(map[nr][nc] == 0 && nr > 0 && nr <= N && nc > 0 && nc <= N)//장애물 없을 경우
            {
                if(distance(cr, cc) > distance(nr, nc)) // 거리가 1 가까워지는 경우에만
                {
                    //std::cout << num + 1 << "번 " << nr << " " << nc << "로 이동\n"; 
                    runner_list[num].r = nr;
                    runner_list[num].c = nc;
                    result++;
                    moved = 1;
                }
            }
        }

        if(runner_list[num].r == Exit.first && runner_list[num].c == Exit.second)//출구 도착한 경우
        {
            runner_list[num].arrived = 1;
        }
    }
}

std::pair<int, int> axisRotation(int r, int c, double center_r_, double center_c_)
{
    double nr = (double)r - center_r_;
    double nc = (double)c - center_c_;
    std::pair<int, int> temp;
    temp.first = nc + center_r_;
    temp.second = -nr + center_c;
    return temp;
}

void rotate(int map_[][12]);



int leftRunner()
{
    int temp = 0;
    for(int num = 0; num < runner_list.size(); num++)
    {
        if(runner_list[num].arrived == 0)
        {
            temp++;
        }
    }
    return temp;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            std::cin >> map[i][j];
        }
    }

    int r, c;
    for(int i = 0; i < M; i++)
    {
        std::cin >> r >> c;
        runner_list.push_back(Runner{i,r,c,0});
    }
    std::cin >> r >> c;
    Exit.first = r;
    Exit.second = c;

    //printMap();
    // std::ofstream file;
    // file.open("out2.txt",std::ios_base::out | std::ios_base::app);
    // std::cout.rdbuf(file.rdbuf());

    while(1)
    {
        if(total_time == K) break;
        if(leftRunner == 0) break;

        //printMap();
        move();
       // printMap();
        rotate(map);
        total_time ++;
    }
   // std::cout << "time : " << total_time << "\n";
    std::cout << result << "\n" << Exit.first << " " << Exit.second << "\n";
    

    return 0;
}


void printMap()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int printed = 0;
            if(i == Exit.first && j == Exit.second)
            {
                std::cout << -1 << "    ";
                printed =  1;
            }
            else
            {
                int space = 0;
                for(int k = 0; k < runner_list.size(); k++)
                {
                    if(runner_list[k].arrived == 1) continue;
                    if(runner_list[k].r == i && runner_list[k].c == j)
                    {
                        std::cout  <<k + 1<< "'";
                        space++;
                        printed = 1;
                    }
                }
                if(printed == 1)
                {
                    for(int i = 0; i < 4-space; i++)
                    {
                        std::cout << " ";
                    }
                }
            }    
            if(printed == 0)
            {
                if(map[i][j] >= 0)
                {
                    std::cout << map[i][j] << "    ";
                }
            }   
        }
        std::cout << "\n\n";     
    }
    std::cout << "Exit : " << Exit.first << " " << Exit.second << "\n";
    std::cout << "\n";
}

void rotate(int map_[][12])
{
    int slen = 100;
    int dist = 100;
    int lr = 20; int lc = 20; int rr = 20; int rc = 20;
    //사각형 설정
    for(int num = 0; num < runner_list.size(); num++)
    {
        if(runner_list[num].arrived == 1) continue;

        //한 변의 길이 구하기
        int clen;
        int square_case;
        // int temp_dist = std::min(std::abs(runner_list[num].c - Exit.second),
        // std::abs(runner_list[num].r - Exit.first));

        // if(dist < temp_dist) continue;

        // dist = temp_dist;
        // std::cout << "dist : "<<temp_dist << " \n";

        clen = std::max(std::abs(runner_list[num].c - Exit.second), std::abs(runner_list[num].r - Exit.first ));

        //std::cout << "clen : " << clen << "\n";

        if(clen <= slen) //사각형 변 길이가 짧아지거나 길어진 경우
        {
            if(clen < slen)
            {
                lr = 20; lc = 20; rr = 20; rc = 20;
            }
            slen = clen;
            

            //사각형 좌상단, 우 하단 좌표 설정
            int temp_c, temp_r;
            
            if(std::abs(runner_list[num].c - Exit.second) != std::abs(runner_list[num].r - Exit.first ))//
            {
               temp_c = std::max(runner_list[num].c, Exit.second);
               temp_r = std::max(runner_list[num].r, Exit.first);

               if(temp_c - slen < 1){ temp_c = 1;}
               else if(temp_c - slen <= lc){temp_c -= slen;}
               if(temp_r - slen < 1) {temp_r = 1;}
               else if(temp_r - slen <= lr){temp_r -= slen;}
                //std::cout << temp_r << " : " <<temp_c << "\n";
            }
            else // 대각선 위치일 때
            {
                temp_c = std::min(runner_list[num].c, Exit.second);
                temp_r = std::min(runner_list[num].r, Exit.first);
            }
            if(temp_r <= lr)
            {
                if(temp_c > lc && lr == temp_r)
                {
                    continue;
                    //std::cout << "sex\n";
                } 
                else{
                    lr = temp_r;
                    lc = temp_c;
                    rr = lr + slen;
                    rc = lc + slen;
                }
            }
        }//std::cout << lr << " " << lc << " " << rr << " " << rc << "\n";
    }

    

    //중앙 좌표 구하기
    center_r = (double)((double)rr + (double)lr)/2;
    center_c = (double)((double)rc + (double)lc)/2;
    //std::cout << center_r << " " << center_c << "\n";
     //좌표 0 일경우 더 빼줘야함.

    //회전
    if(slen == 100) return;

    //범위 내 벽 회전
    int current_r, current_c;
    std::pair<int, int> rotated;
    for(int i = lr; i <= rr; i++)
    {
        for(int j = lc; j <= rc; j++)
        {
            rotated = axisRotation(i, j, center_r, center_c);
           // std::cout << rotated.first << " " << rotated.second << "\n";
            temp_map[rotated.first][rotated.second] = map_[i][j];
        }
    }
    for(int i = lr; i <= rr; i++)
    {
        for(int j = lc; j <= rc; j++)
        {
            map_[i][j] = temp_map[i][j];
            if(map_[i][j] > 0)
            {
                map_[i][j]--; //회전된 벽에 대해 -1;
            }
        }
    }

    //범위 내 모험가 이동
    for(int num = 0; num < runner_list.size(); num++)
    {
        if(runner_list[num].arrived == 1) continue;

        if(runner_list[num].r >= lr && runner_list[num].r <= rr
        && runner_list[num].c >= lc && runner_list[num].c <= rc) //범위 안일경우
        {
            rotated = axisRotation(runner_list[num].r, runner_list[num].c, center_r, center_c);
            runner_list[num].r = rotated.first;
            runner_list[num].c = rotated.second;
        }
    }
    //출구 이동
    rotated = axisRotation(Exit.first, Exit.second, center_r, center_c);
    Exit.first = rotated.first; Exit.second = rotated.second;

}