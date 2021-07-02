#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string input;
    std::cin >> input;

    std::vector<std::string> arr={"c=","c-","dz=","d-","lj","nj","s=","z="};

    int index = 0;
    for(int i = 0 ; i < arr.size();i++)
    {
        index = input.find(arr[i]);
        while(index != std::string::npos)
        {
            input.replace(index, arr[i].length(), "@");
            index = input.find(arr[i]);
        }
    }
    std::cout << input.length();
}