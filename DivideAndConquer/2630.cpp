/*
    중앙을 기준으로 색종이를 4분할 해서 풀이.
*/
#include <iostream>

int paper[128][128];

int N;

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
}