#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::vector<char> alphabet;

    std::cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        input[i] = std::toupper(input[i]);
    }
    bool exist = false;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < alphabet.size(); j++)
        {
            if (alphabet[j] == input[i])
                exist = true;
        }
        if (exist == false)
        {
            alphabet.push_back(input[i]);
        }
        exist = false;
    }

    char maxChar;
    int max = 0;

    for (int i = 0; i < alphabet.size(); i++)
    {
        int temp = 0;
        for (int j = 0; j < input.length(); j++)
        {
            if (alphabet[i] == input[j])
                temp++;
        }
        if (max < temp)
        {
            max = temp;
            maxChar = alphabet[i];
        }
        else if (max == temp)
        {
            maxChar = '?';
        }
    }

    std::cout << maxChar;
}