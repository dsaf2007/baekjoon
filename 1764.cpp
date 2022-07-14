#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::set<std::string> input;
    std::set<std::string> output;
    int N, M, cnt =0;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::string temp;
        std::cin >> temp;
        input.insert(temp);
    }

    for(int i = 0; i < M; i++)
    {
        std::string temp;
        std::cin >> temp;
        if(input.find(temp) != input.end())
        {
            cnt++;
            output.insert(temp);
        }
    }
    std::cout << cnt << "\n";
    for(auto i : output)
    {
        std::cout << i << "\n";
    }

    return 0;
}