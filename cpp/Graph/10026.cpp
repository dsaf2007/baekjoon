#include <iostream>
#include <string>

using namespace std;

int result1, result2;

int N;
int dy[] = {1, -1, 0, 0}; // 상, 하, 우, 좌
int dx[] = {0, 0, 1, -1};

char map[101][101];
bool visited1[101][101]; // 정상
bool visited2[101][101]; // 비정상

void sol1(int r, int c, char color) //일반사람
{
    if (visited1[r][c])
        return;
    else
    {
        if (r >= 0 && r < N && c >= 0 && c < N && map[r][c] == color)
        {
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                visited1[r][c] = true;
                sol1(nr, nc, color);
            }
        }
    }
}

void sol2(int r, int c, char color) //색약
{
    if (visited2[r][c])
        return;
    else
    {
        if (r >= 0 && r < N && c >= 0 && c < N)
        {
            if(color == 'R' || color == 'G')
            {
                if(map[r][c] == 'B')
                {
                    return;
                }    
            }
            else if(color == 'B')
            {
                if(map[r][c] == 'R' || map[r][c] == 'G')
                {
                    return;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                visited2[r][c] = true;
                sol2(nr, nc, color);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < input.length(); j++)
        {
            map[i][j] = input[j];
            visited1[i][j] = false;
            visited2[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!visited1[i][j])
            {
                sol1(i, j, map[i][j]);
                result1++;
            }
            if(!visited2[i][j])
            {
                sol2(i,j,map[i][j]);
                result2++;
            }
        }
    }

    cout << result1 << " " << result2;

    return 0;
}