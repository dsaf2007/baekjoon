#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> computer[101];
int visited[101];
int count;
int root;
int N;
int M;

void dfs(int root)
{
    if(visited[root] == 1)
        return;
    
    visited[root] = 1;
    count++;
        
    for(int i = 0; i < computer[root].size(); i++)
    {
        dfs(computer[root][i]);
    }
}
int main()
{
    std::cin >> N >> M;
    for(int i = 1; i <= M; i++)
    {
        int a,b;
        std::cin >> a >> b;
        computer[a].push_back(b);//노드 연결
        computer[b].push_back(a);
    }

    dfs(1);

    std::cout << count - 1; //1번 자기 자신은 제외해야함.

    return 0;
}