#include <iostream>

int N, M;
int result[8];

void combination(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(k != 0 && result[k-1] > i) continue;
            result[k] = i;
            combination(k+1);
        }
    }
}

int main()
{
    std::cin >>N >> M;
    combination(0);
    return 0;
}