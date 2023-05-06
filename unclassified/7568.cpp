#include <iostream>
#include <vector>
#include <cstdlib>

int main()
{
    int n,a,b;
    int out = 1;
    std::vector<std::pair<int,int>> input;
    std::vector<std::pair<int,int>> original;
    std::cin >> n;
    std::pair<int,int> temp;

    for(int i = 0; i < n; i++)
    {
        std::cin >> a >>b;
        input.push_back(std::make_pair(a,b));
    } 
    for(int i = 0 ; i < n; i++)
    {
                    out =1;
        for(int j = 0; j < n; j++)
        {
            if(input[i].first < input[j].first && input[i].second < input[j].second)
            {
                out++;
            }
        }
        std::cout << out << " ";
    }

}