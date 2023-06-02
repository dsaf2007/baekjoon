#include <iostream>

int result[9];
bool visited[9];

int N,M;

void combination(int k)
{
    if(k == M)
    {
        for(int i = 0; i < M; i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for(int i =1; i<= N; i++)
        {
            result[k] = i;
            combination(k+1);
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