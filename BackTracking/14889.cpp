#include <iostream>
#include <algorithm>

int n;
int arr[21][21];
int visited[21];

int min = INT16_MAX;
int temp;

void make_team(int k, int idx)
{
    if (k == n / 2) // 전체인원의 절반 -> 팀 구성이 완료 되었을 때
    {
        int team1 = 0;
        int team2 = 0;
        // 팀 점수 계산
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i] == 1 && visited[j] == 1)
                {
                    team1 += arr[i][j];
                }
                if (visited[i] == 0 && visited[j] == 0)
                {
                    team2 += arr[i][j];
                }
            }
        }
        temp = std::abs(team1 - team2);
        if (min > temp)
        {
            min = temp;
        }
        return;
    }
    for (int i = idx; i < n; i++)
    {
        // 팀 만들기
        if (visited[i] != 1)
        {
            visited[i] = 1;
            make_team(k + 1, i + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    make_team(0, 0);

    std::cout << min;
    return 0;
}