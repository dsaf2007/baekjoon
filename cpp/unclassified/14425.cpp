#include <iostream>
#include <map>
#include <string>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N ,M;
    int cnt =0;
    std::cin >> N >> M;

    std::set<std::string> s;

    for(int i = 0; i < N; i++)
    {
        std::string temp;
        std::cin >> temp;
        s.insert(temp);
    }

    for(int i = 0; i < M; i++)
    {
        std::string temp;
        std::cin >>temp;
        if(s.find(temp) != s.end()) cnt++;
    }
    std::cout <<cnt;
    
    return 0;
}