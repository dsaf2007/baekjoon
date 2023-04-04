#include <iostream>
#include <vector>
#include <algorithm>
// bruteforce 로 풀어보기.

int n, m, size;
int city[51][51];
std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> chicken;
std::vector<std::vector<int>> combi;
std::vector<int> result;

int arr[13];

void combination(int r,int next) // nCr
{
    if (r == m)
    {
        std::vector<int> temp;
        for (int i = 0; i < m; i++)
        {
            temp.push_back(arr[i]);
        }
        combi.push_back(temp);
        return; 
    }
    else
    {
        int chicken_size = chicken.size();
        for(int i = next; i < chicken_size; i++)
        {
            arr[r] = i;
            combination(r + 1, i + 1);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            std::cin >> temp;
            city[i][j] = temp;
            if (temp == 1)
            {
                house.push_back(std::pair{i, j});
            }
            if (temp == 2)
            {
                chicken.push_back(std::pair{i, j});
            }
        }
    }

    combination(0,0);

    for(auto com : combi)
    {
        int sum = 0;
        for(auto h : house)
        {
            int dist_min = 99999;
            for(auto c : com)
            {
                int x = chicken[c].first;
                int y =  chicken[c].second;
                int temp = std::abs(h.first - x) + std::abs(h.second - y);
                if(temp < dist_min)
                {
                    dist_min = temp;
                }
            }
            sum += dist_min;
        }
        result.push_back(sum);
    }

    std::cout << *std::min_element(result.begin(), result.end()) << std::endl;
    
    return 0;
}