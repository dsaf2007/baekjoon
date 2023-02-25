#include <iostream>
#include <algorithm>
#include <vector>

int n;
int graph[25][25];
int visited[25][25];

std::vector<int> result;
int cnt;

void dfs(int x, int y)
{
    if (x >= 0 || x < 25 || y >= 0 || y < 25)
    {
        if (visited[x][y] != 1 && graph[x][y] == 1)
        {
            visited[x][y] = 1;
            cnt++;
            dfs(x + 1, y);
            dfs(x, y + 1);
            dfs(x - 1, y);
            dfs(x, y - 1);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::string input;
        std::cin >> input;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = input[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt = 0;
            if (graph[i][j] == 1 && visited[i][j] == 0)
            {
                dfs(i, j);
                if (cnt > 0)
                {
                    result.push_back(cnt);
                }
            }
        }
    }

    std::sort(result.begin(), result.end());

    std::cout << result.size() << "\n";
    for (auto a : result)
    {
        std::cout << a << "\n";
    }

    return 0;
}