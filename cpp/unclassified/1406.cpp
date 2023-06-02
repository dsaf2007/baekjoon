#include <iostream>
#include <list>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::list<char> L;


    std::string input;

    std::cin >> input;

    for(auto s : input)
    {
        L.push_back(s);
    }
    auto cursor = L.end();//가장 끝에 커서 위치

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        char cmd;
        std::cin >> cmd;


        if(cmd == 'P')
        {
            char ch;
            std::cin >> ch;
            L.insert(cursor, ch);
        }
        else if(cmd == 'L')
        {
            if(cursor != L.begin()) cursor--;
        }
        else if(cmd == 'D')
        {
            if(cursor != L.end()) cursor++;
        }
        else
        {
            if(cursor != L.begin())
            {
                cursor--;
                L.erase(cursor);
            }
        }
    }

    for(auto l : L)
    {
        std::cout << l;
    }std::cout << "\n";

    return 0;
}