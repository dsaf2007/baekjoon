/*
    숫자 선택하여 중복되는 수열 없이 출력 --> 조합
*/
#include <iostream>

int N, M;

int arr[8];
int visited[8];

void combination(int pos)
{   
    if(pos == M)
    {
        //조합 출력;
        for(int i = 0; i < M; i++)
        {
            std::cout << arr[i] << " ";
        }std::cout << "\n";
    }
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                arr[pos] = i;
                combination(pos + 1);
                visited[i] = 0;
            }
        }
    }
}   

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M;

    combination(0);

    return 0;
}