#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<char>> vec_arr(8);
    vec_arr.clear();
    vec_arr[0].push_back('A');vec_arr[0].push_back('B');vec_arr[0].push_back('C');
    vec_arr[1].push_back('D');vec_arr[1].push_back('E');vec_arr[1].push_back('F');
    vec_arr[2].push_back('G');vec_arr[2].push_back('H');vec_arr[2].push_back('I');
    vec_arr[3].push_back('J');vec_arr[3].push_back('K');vec_arr[3].push_back('L');
    vec_arr[4].push_back('M');vec_arr[4].push_back('N');vec_arr[1].push_back('O');
    vec_arr[5].push_back('P');vec_arr[5].push_back('Q');vec_arr[5].push_back('R');vec_arr[5].push_back('S');
    vec_arr[6].push_back('T');vec_arr[6].push_back('U');vec_arr[6].push_back('V');
    vec_arr[7].push_back('W');vec_arr[7].push_back('X');vec_arr[7].push_back('Y');vec_arr[7].push_back('Z');

    std::string input;
    std::cin >> input;

    int dial_time=0;
    for(int i=0;i<input.length();i++)
    {
        for(int j=0;j<8;j++)
            for(int k=0;k<vec_arr[j].size();k++)
            {
                if(input[i] == vec_arr[j][k])
                    dial_time +=(j+3);
            }
    }

    std::cout << dial_time;
}