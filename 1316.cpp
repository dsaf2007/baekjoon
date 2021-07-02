#include <iostream>
#include <vector>

int main()
{
    std::vector<char> vec;
    int num;
    std::cin >> num;

    std::string* input = new std::string[num];
    for (int i = 0; i < num; i++)
    {
        std::cin >> input[i];
    }

    int group_num = 0;

 
    for (int k = 0; k < num; k++)
    {
        int group = 0;
        char prev_char = input[k][0];
        vec.clear();
        for (int i = 0; i < input[k].length(); i++)
        {
            if (input[k][i] != prev_char)
            {
                for (int j = 0; j < vec.size(); j++)
                {
                    if (input[k][i] == vec[j])
                    {
                        group = 1;
                    }
                }
                vec.push_back(input[k][i]);
                prev_char = input[k][i];
            }
        }
        if (group == 0)
            group_num++;
    }

    std::cout << group_num;

}