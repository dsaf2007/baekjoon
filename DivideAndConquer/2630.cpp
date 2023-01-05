/*
    중앙을 기준으로 색종이를 4분할 해서 풀이.
*/
#include <iostream>

int paper[128][128];

int N;

int w, b;

void solution(int x, int y, int n)
{
    int color = paper[x][y];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(paper[i][j] != color)
            {
                solution(x,y,n);
                solution(x+ n/2, y, n);
                solution(x, y+n/2, n);
                solution(x + n/2, y + n/2, n);

                return;
            }
        }
    }
    if(color == 1)
        b ++;
    else
        w++;

    return;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> paper[i][j];
        }
    }

    solution(0,0,N);

    std::cout << w << "\n" << b << "\n";
}