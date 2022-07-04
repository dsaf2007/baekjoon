#include <iostream>
#include <set>
#include <map>
#include <string>

std::string index[100001];

bool isNumber(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::map<std::string, int> pkmn;
    std::string temp;

    for (int i = 0; i < N; i++)
    {
        std::cin >> temp;
        pkmn.insert(std::make_pair(temp, (i + 1)));
        index[i] = temp;
    }

    for (int i = 0; i < M; i++)
    {
        std::cin >> temp;
        if (pkmn.find(temp) != pkmn.end())
        {
            std::cout << pkmn.find(temp)->second << "\n";
        }
        else
        {
            std::cout << index[stoi(temp) - 1] << "\n";
        }
    }
    return 0;
}