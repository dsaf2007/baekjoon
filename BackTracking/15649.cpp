#include <iostream>

using namespace std;

int N, M;

int arr[9];
int visited[9];

void dfs(int k)
{
    if(k == M)
    {
        for(int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
    }
    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            arr[k] = i;
            dfs(k + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    dfs(0);

    return 0;
}