#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1}; // 상 우 하 좌
int map[51][51];

int N, M;
int result;
int d, r, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cin >> map[n][m];
        }
    }

    bool canClean = true;
    bool cleaned = false;

    while (canClean)
    {
        cleaned = false;

        int nr;
        int nc;

        //cout << "r : " << r << " c : " << c << "\n";

        for (int i = 1; i <= 4; i++)
        {
            int nd = (d + i) % 4;
            if(map[r][c] == 0)
            {
                map[r][c] = -1;
                result++;
            }
            nr = r + dr[nd];
            nc = c + dc[nd];
            //if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue; //칸을 벗어나는 경우
            if(map[nr][nc] != 0) continue; //청소가 불가능한 칸인 경우

            //map[nr][nc] = -1; //청소완료
            //result++;
            r = nr;
            c = nc;
            d = nd;
            cleaned = true;
            break;
        }
        if (cleaned == false) // 네 방향 모두 없을 경우
        {
            int temp_r = r - dr[d];
            int temp_c = c - dc[d];

            if(map[temp_r][temp_c] == 1) //뒤쪽이 벽일 경우
            {
                canClean = false;
                break;
            }    
            else
            {
                r = temp_r;
                c = temp_c; //뒤로 이동
            }
            
        }
    }

    cout << result << "\n";

    return 0;
}