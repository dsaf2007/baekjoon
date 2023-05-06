#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string input;
    std::cin >> input;
    std::set<std::string> a;
    std::string temp;

    for (int i = 0; i <= input.length(); i++)
    {
        for (int j = 1; j <= input.length() - i; j++)
        {
            temp = input.substr(i, j);
            a.insert(temp);
        }
    }
    std::cout << a.size();
    return 0;
}