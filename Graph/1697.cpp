#include <iostream>
#include <vector>
#include <queue>

int N;
int K;

int visited[100001];
int t[100001];

int move[2] ={1, -1};

void bfs()
{
    std::queue<int> q;
    q.push(N);
    visited[N] = 1;
    t[N]++;
    while(!q.empty())
    {
        int inq = q.front();
        q.pop();

        if(inq == K)
        {
            break;
        }
        for(int i = 0; i < 3; i++)
        {

            int temp = inq;
            if(i ==2 )
            {
                temp *= 2;
            }
            else
            {
                temp += move[i];
            }
            if(temp > 100000 || temp < 0)
            {
                continue;
            }
            if(visited[temp] == 1)
            {
                continue;
            }
            visited[temp] = 1;
            q.push(temp);

            t[temp] = t[inq] + 1;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> K;

    bfs();
    std::cout << t[inq] - 1;
    return 0;
}