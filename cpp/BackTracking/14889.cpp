#include <iostream>
#include <algorithm>

using namespace std;

int N;
int members[22][22];
int visited[22];
int min_score = INT16_MAX;
int score_gap;

void getTeam(int k, int idx)
{
    if(k == N/2)
    {
        int team1 = 0, team2 = 0;

        //팀 점수 계산
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(visited[i] == 1 && visited[j] == 1)
                {
                    team1 += members[i][j];
                }
                if(visited[i] == 0 && visited[j] == 0)
                {
                    team2 += members[i][j];
                }
            }
        }
        score_gap = abs(team1-team2);

        min_score = min(score_gap, min_score);

        return;
    }
    for(int i = idx; i <= N; i++)
    {
        if(visited[i] != 1)
        {
            visited[i] = 1;
            getTeam(k + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> members[i][j];
        }
    }

    getTeam(0, 1);

    cout << min_score << "\n";

    return 0;
}