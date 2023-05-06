#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char map[1001][1001];
int dist[1001][100];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
void bfs_fire(int r, int c, int dist)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    for(int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < C; j++)
        {
            map[i][j] = input[j];
        }
    }


    return 0;
}