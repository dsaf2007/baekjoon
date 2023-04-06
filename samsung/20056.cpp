#include <iostream>
#include <vector>

int N, M, K;

class FireBall;

std::vector<FireBall> map[51][51];
std::vector<FireBall> temp_map[51][51];
std::vector<FireBall> input;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    return false;
}

class FireBall
{
public:
    FireBall();

    FireBall(int r, int c, int m, int s, int d)
    {
        this->r = r;
        this->c = c;
        this->m = m;
        this->d = d;
        this->s = s;
    };
    int r;
    int c;
    int m;
    int d;
    int s;

    friend std::ostream &operator<<(std::ostream &os, const FireBall &f)
    {
        os << f.r << " " << f.c << " " << f.m << " " << f.s << " " << f.d << std::endl;
        return os;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int r, c, m, d, s;
        std::cin >> r >> c >> m >> s >> d;
        input.push_back(FireBall{r, c, m, s, d});
        map[input[i].r][input[i].c].push_back(input[i]);
    }

    for (int k = 0; k < K; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {

               for(auto a : map[i][j]) //이동
               {
                    int nx = (i + dx[a.d]*a.s) % N;
                    int ny = (j + dy[a.d]*a.s) % N;

                    if(nx <= 0)
                    {
                        nx += N;
                    }
                    if(ny <= 0)
                    {
                        ny += N;
                    }

                    temp_map[nx][ny].push_back(FireBall{nx, ny, a.m, a.s, a.d});
               }
            }
        }
        for (int i = 1; i <= N; i++)//map으로 옮김
        {
            for (int j = 1; j <= N; j++)
            {
                map[i][j] = temp_map[i][j];

                if(map[i][j].size() <= 1)
                {
                    temp_map[i][j].clear();
                    continue;
                }

                FireBall temp(0,0,0,0,0);
                
                bool even = true;
                bool odd = true;
                for(auto a : temp_map[i][j])
                {
                    if(temp_map[i][j].size() > 1)
                    {
                        temp.m += a.m;
                        temp.s += a.s;

                        if(isEven(a.d))//짝
                        {
                            odd = false;
                        }
                        if(!isEven(a.d))//홀
                        {
                            even = false;
                        }
                    }
                }
                temp.m /= 5;
                temp.s /= temp_map[i][j].size();

                map[i][j].clear();
                temp_map[i][j].clear();

                if(temp.m == 0)
                {
                    continue;
                }

                if(even || odd)
                {
                    for(int t = 0; t < 8; t += 2)
                    {
                        map[i][j].push_back(FireBall{i,j,temp.m, temp.s, t});
                    }
                }
                else
                {
                    for(int t = 1; t < 8; t += 2)
                    {
                        map[i][j].push_back(FireBall{i,j,temp.m, temp.s, t});
                    }
                }
            }
        }
    }

    int sum = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (auto a : map[i][j])
            {
                sum += a.m;
            }
        }
    }

    std::cout << sum << "\n";

    return 0;
}