#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N,M;
    std::vector<int> a;
    std::vector<int> b;

    std::cin >> N;
    int temp;
    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        a.push_back(temp);
    }
    std::cin >> M;
    for(int i= 0; i < M; i++)
    {
        std::cin >> temp;
        b.push_back(temp);
    }

    std::sort(a.begin(), a.end());

    for(auto i:b)
    {
        std::cout << (std::binary_search(a.begin(), a.end(), i)) << " ";
    }
    return 0;
}