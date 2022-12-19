/*
    dfs 이용하여 해결.
    무방향 그래프로 생각하고 풀이.
    현재 정점에서 위, 아래, 좌, 우 로 이동하여 1이 나오지 않을 때 까지 탐색.
    bfs로도 풀이해보기.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdlib>


int N;
int size;
char graph[25][25];
std::vector<int> size_vec;
int visited[25][25];

void dfs(int i, int j)
{
    if(visited[i][j] == 1)
    {
        return;
    }
    if(graph[i][j] == '0')
    {
        return;
    }

    if(i < 0 || i >= N || j < 0 || j >= N)
    {
        return;
    } 
    visited[i][j] = 1;
    size++;

    //가능한 이동 경우의 수는 8이지만, 상,하,좌,우 만 가능하므로 네개. 분할정복과 유사
    dfs(i, j+1);
    dfs(i,j-1);
    dfs(i+1, j);
    dfs(i-1,j);
    

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;


    for (int i = 0; i < N; i++)
    {
        std::string temp;
        std::cin >> temp;
        for(int j = 0; j < N; j++)
        {
            graph[i][j] = temp[j];
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(visited[i][j] == 1)
                continue;
            if(graph[i][j] == '0')
                continue;
            size = 0;
            dfs(i,j);
            size_vec.push_back(size);
        }
    }

    std::sort(size_vec.begin(), size_vec.end());
    std::cout <<size_vec.size() << "\n";
    for(auto a : size_vec)
    {
        std::cout << a << "\n";
    }
    return 0;
}