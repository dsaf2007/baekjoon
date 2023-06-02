#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> com[101];
int visited[101];
int n,m, cnt;

void dfs(int r)
{
    if(visited[r] != 1)
    {
        visited[r] = 1;
        cnt++;
        for(int i = 0; i < com[r].size(); i++)
        {
            dfs(com[r][i]);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    dfs(1);

    cout << cnt - 1;

    return 0;
}