#include <iostream>
#include <vector>

int n, k;

std::vector<std::pair<int, int>> v;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int weight, value;
        std::cin >> weight >> value;

        v.push_back(std::pair<int,int>(weight,value));
    }

    return 0;
}