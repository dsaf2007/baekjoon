#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//int arr_n[500000];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::vector<int> arr_n;
    int N,M;
    int temp;
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        // arr_n[i] = temp;
        arr_n.push_back(temp);
    }
    std::sort(arr_n.begin(), arr_n.end());

    std::cin >> M;
    for(int i = 0; i < M; i++)
    {
        std::cin >> temp;
            std::cout << std::upper_bound(arr_n.begin(), arr_n.end(),temp) - std::lower_bound(arr_n.begin(), arr_n.end(),temp) << " ";
    }
    return 0;
}