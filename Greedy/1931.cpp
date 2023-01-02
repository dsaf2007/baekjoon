#include <iostream>
#include <vector>
#include <algorithm>

/*
    종료시간을 기준으로 회의 시간표 우선 정렬
    bool compare를 만들어서 sort로 비교.
    종료시간이 동일할 경우 시작시간이 작은 경우를 앞으로.
*/

std::vector<std::pair<int, int>> tt;
int N;

bool compare(const std::pair<int, int>& a,const std::pair<int, int>& b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        tt.push_back(std::make_pair(a,b));
    }

    int count = 1;
    std::sort(tt.begin(), tt.end(),compare);

    int time = tt[0].second;
    for(int i = 1; i < N; i++)
    {
        if(time <= tt[i].first)
        {
            count ++;
            time = tt[i].second;
        }
    }
    std::cout << count;
}