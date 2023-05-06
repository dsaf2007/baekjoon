#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    std::cin >> input;

    for(int i = 0 ; i < alphabet.length() ; i++)
    {
        int out = -1;
        for(int j = 0; j < input.length(); j++)
        {
            if(input[j] == alphabet[i])
               {
                 //std::cout << j << " ";
                 out = j;
                 break;  
               } 
        }
        std::cout << out << " ";
    }
}
