#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>


    int result,temp,num;    

int main()
{
    int input;
    std::cin >> input;
    std::string num;
    for(int i = 0 ; i < input; i ++)
    {
        num = std::to_string(i);
        temp = i;
        for(int j = 0; j < num.length(); j++)
        {
            temp += (int)(num[j] - '0');
        }
        if(temp == input)
        {
            result = i;
            break;
        }
    }


    std::cout << result;

}