#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N,M,cnt = 0;

    std::set<int> arr_1;
    std::set<int> arr_2;

    std::cin >> N >> M;
    int input;
    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        arr_1.insert(input);
    }
    for(int i = 0; i < M; i++)
    {
        std::cin >> input;
        arr_2.insert(input);
        if(arr_1.find(input) == arr_1.end())
        {
            cnt++;
        }
    }
    for(auto i : arr_1)
    {
        if(arr_2.find(i) == arr_2.end())
            cnt++;
    }

    std::cout << cnt;
    return 0;
}