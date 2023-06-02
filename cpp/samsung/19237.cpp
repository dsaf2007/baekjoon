#include <iostream>
#include <vector>
#include <algorithm>


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int sharkAmount;

class Shark
{
public:
    Shark(){}

    Shark(int num, int x, int y)
    {
        this->num = num;
        this->x = x;
        this->y = y;
    }
    int dirList[4][4];
    int dir;
    int num;
    int x;
    int y;
    int alive = 1;
};

bool compare(Shark a, Shark b)
{
    return a.num < b.num;
}

int N, M, K;

std::pair<int, int> map[21][21]; //first = 번호 , second = 향기 남은시간
std::vector<Shark> sharkList;

std::vector<int> sharkPos[21][21]; // 해당 칸에 상어들 이동. 벡터 길이가 1 초과 이면 여러마리인 것으로 간주하여 삭제작업 시작

void moveShark()
{
    //std::cout << "size : " << sharkList.size() << "\n";
    for(auto s : sharkList)
    {
        if(s.alive == 0) continue;
        int nx = -1, ny = -1, ndir = -1;
        int cx = s.x;
        int cy = s.y;
        int cdir = s.dir;
        //인접한 칸중 아무 냄새 없는지 먼저 점검
        int moved = 0;
        for(int i = 0; i < 4; i++)
        {
            //std::cout << "sdir : " << cdir << "\n";
            ndir = s.dirList[s.dir][i];
            //std::cout << "ndir : " << ndir << "\n";
            nx = cx + dx[ndir];//우선순위에 따른 방향
            ny = cy + dy[ndir];

            if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;

            if(map[nx][ny].second == 0) //냄새가 없는 칸이면 이동
            {
                s.x = nx;
                s.y = ny;
                s.dir = ndir;

                //이동하여 향기 남기기
                map[nx][ny].first = s.num;
                map[nx][ny].second = K;
                //기존 상어 위치 삭제, 새 위치 추가
                sharkPos[cx][cy].clear();
                //std::cout << "s.num : " << s.num << "\n";
                //std::cout << "nx : " << nx << " ny : " <<ny <<"\n";
                sharkPos[nx][ny].push_back(s.num);
                //std::cout << sharkPos[nx][ny][0] <<  "\n";
                moved = 1;
                break;
            }
        }

        //모든 칸이 냄새가 있을 때
        if(moved == 0)
        {
            for(int i = 0; i < 4; i++)
            {
                ndir = s.dirList[cdir][i];
                nx = cx + dx[ndir];//우선순위에 따른 방향
                ny = cy + dy[ndir];

                if(nx < 0 || nx >= N || ny < 0 || ny >=N) continue;


                if(map[nx][ny].first == s.num) //나의 냄새에 이동
                {
                    s.x = nx;
                    s.y = ny;
                    s.dir = ndir;

                    //이동하여 향기 남기기
                    map[nx][ny].first = s.num;
                    map[nx][ny].second = K;
                    //기존 상어 위치 삭제, 새 위치 추가
                    sharkPos[cx][cy].clear();
                    sharkPos[nx][ny].push_back(s.num);
                    moved = 1;
                    break;
                }
            }
        }
    }
}


void checkShark()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(sharkPos[i][j].size() > 1)//상어가 한마리 이상 있을 때
            {
                std::sort(sharkPos[i][j].begin(), sharkPos[i][j].end(), std::greater<>());
                for(int k = 1; k < sharkPos[i][j].size(); k++)
                {
                    int num = sharkPos[i][j][k];
                    std::cout << sharkPos[i][j].size() << std::endl;
                    //std::cout << "num : " << num << "\n";
                    sharkList[num].alive = 0; // 상어 죽이고
                    std::remove(sharkPos[i][j].begin(), sharkPos[i][j].end(), num);
                    sharkAmount--; //총 상어수 감소
                }
            }
        }
    }
}

void reduceScent()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j].second > 0)
            {
                map[i][j].second--;
                if(map[i][j].second == 0)
                {
                    map[i][j].first = 0; //냄새 지워지면 번호 지우기
                }
            }
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    sharkAmount = M;

    sharkList.push_back(Shark{0,0,0}); // 상어 번호 때문에 빈 상어 추가

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int a;
            std::cin >> a;
            if(a == 0)
            {
                map[i][j] = std::pair{0, 0};
            }
            else
            {
                map[i][j] = std::pair{a, K};
                sharkList.push_back(Shark{a,i,j});
                sharkPos[i][j].push_back(a);
                //std::sort(sharkPos.begin(), sharkPos.end());
            }
        }
    }
    
    std::sort(sharkList.begin(), sharkList.end(), compare);

    for(int i = 1; i <= M; i++) //각 상어의 방향
    {
        int dir;
        std::cin >> dir;
        sharkList[i].dir = dir - 1; // 방향 주입. 인덱스 0부터 시작해서 -1 해서 입력
    }

    for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int dir;
                std::cin >> dir;
                sharkList[i].dirList[j][k] = dir - 1; 
            }
        }
    }

    sharkList[0].alive = 0;

    /*for(int i = 1; i <= M; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                std::cout << "dir : "<<sharkList[i].dirList[j][k] << " ";
            }
            std::cout << "\n";
        }
    }*/
    int time = 0;

    while(time < 1000)
    {
        time++;
        //std::cout << time << std::endl;
        moveShark();
        checkShark();
        reduceScent();

        if(sharkAmount == 1)
        {
            break;
        }
    }
    std::cout << time << "\n";
    return 0;
}