#include <iostream>
#include <vector>

int n;
int result;
std::vector<std::pair<int, int>> dline;
std::vector<std::pair<int, int>> iline;
std::vector<std::pair<int, int>> pline;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >>n;

    for(int i = 0; i < n; i++)
    {
        int a, b;

        std::cin >> a >> b;

        if(a > b)
        {
            dline.push_back(std::make_pair(a, b));
        }
        else if(a < b)
        {
            iline.push_back(std::make_pair(a,b));
        }
        else if(a == b)
        {
            pline.push_back(std::make_pair(a,b));
        }
    }


}