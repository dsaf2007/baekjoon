#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> graph[101];
int result[101][101];


void dfs(int k, int l)
{
    for(auto x : graph[k])
    {
        if(!result[l][x])
        {
            result[l][x] = 1;
            dfs(x,l);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            if(temp == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        dfs(i,i);
    }

    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}