#include <iostream>
#include <string>
#include <vector>
int main()
{
    int num,sum;
    std::string input;
    std::vector<int> arr;

    std::cin >> num;
    std::cin >> input;

    sum = 0;

    for (int i = 0 ; i < num ; i++)
    {
        //arr.push_back(stoi(input[i]));
        sum += input[i] - '0';
    }

    std::cout << sum;
}