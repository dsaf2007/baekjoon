#incldue <iostream>
#include <vector>

bool visited[9];
int result[9];

void combination(int k, int n, int m)
{
    if(k == m)
    {
        for(int i = 0; i < m; i++)
        {
            std::cout << result[i] << " ";
        }
        std::cout << "\n";
    }
    else
    {
        for(int i = 1; i <= N; i++)
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                result[k] = i;
                combination(k+1, n, m);
                visited[i] = false;
            }
        }
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    
    return 0;
}