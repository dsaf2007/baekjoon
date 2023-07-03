#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Tomato
{
public:
    int h;
    int n;
    int m;
    int day;

    Tomato(int h_, int n_, int m_, int day_)
    {
        this->h = h_;
        this->n = n_;
        this->m = m_;
        this->day = day_;
    }

    
    friend ostream& operator << (ostream &out, Tomato &tomato)
    {
        out << "h : " << tomato.h << " n : " << tomato.n << " m : " << tomato.m << " day : " << tomato.day << "\n";

        return out;
    }

};

int N,
    M, H;

int box[101][101][101];
int day[101][101][101];

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int dh[] = {0, 1, -1};

int result;

queue<Tomato> q;

void print(){
    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cout << box[h][n][m] << " ";
            }cout << "\n";
        }cout << "\n";
    }
}


void bfs()
{
    while(!q.empty())
    {
        Tomato inq = q.front();
        q.pop();

        //cout << inq << "\n";

        for(int i = 0; i < 4; i++)
        {   
            int nr, nc;
            for(int j = 0; j < 3; j++)
            {
                int nh = inq.h + dh[j];
                
                if(dh[j] == 0)
                {
                    nr = inq.n + dr[i];
                    nc = inq.m + dc[i];
                }
                else
                {
                    nr = inq.n;
                    nc = inq.m;
                }
                
                if(nh < 0 || nh >= H) continue;

                if(nr >= 0 && nr < N && nc >= 0 && nc < M && box[nh][nr][nc] == 0)
                {
                    box[nh][nr][nc] = 1;
                    day[nh][nr][nc] = inq.day + 1;
                    q.push(Tomato{nh, nr, nc, day[nh][nr][nc]});

                    result = max(day[nh][nr][nc], result);
                }
            }
            //print();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> H;

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> box[h][n][m];
                if (box[h][n][m] == -1)
                {
                    day[h][n][m] = -1;
                }
                if (box[h][n][m] == 1)
                {
                    q.push(Tomato{h,n,m,0});
                }
            }
        }
    }

    bfs();

    for (int h = 0; h < H; h++)
    {
        for (int n = 0; n < N; n++)
        {
            for (int m = 0; m < M; m++)
            {
                if(box[h][n][m] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << result << "\n";

    return 0;
}