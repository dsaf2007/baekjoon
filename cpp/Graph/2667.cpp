#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int N, cnt;
int map[26][26];
int visited[26][26];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void dfs(int x, int y)
{
    if(visited[x][y] == 0 && map[x][y] == 1)
    {
        cnt++;
        visited[x][y] = 1;
        for(int m = 0; m < 4; m++)
        {
            int nx = x + dx[m];
            int ny = y + dy[m];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N)
            {
                dfs(nx, ny);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = 0; j < N; j++)
        {
            map[i][j] = input[j] - '0';
        }
    }
    vector<int> result;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cnt = 0;
            dfs(i, j);
            if(cnt > 0)
            {
                result.push_back(cnt);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto a : result) 
    {
        cout << a << "\n";
    }

    return 0;
}