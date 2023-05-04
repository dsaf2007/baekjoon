#include <string>
#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>

std::vector<std::string> input_string;

int solution(std::string dartResult) {
    int answer = 0;
    std::string temp;
    int prize = 2;

    bool flag = false;
    for(int i = 0; i < dartResult.length(); i++)
    {
        temp = dartResult[i];
        temp += dartResult[++i];

        if( temp.compare("10") == 0)
        {
            temp = "x";
            temp += dartResult[++i];
        }
        
        if(dartResult[i+1] == '*' || dartResult[i+1] == '#')
            temp += dartResult[++i];
        input_string.push_back(temp);
    }
    
    int num = 0;
    for(int i = 0; i < input_string.size(); i++)
    {
        if(input_string[i].length() == 3)
        {
            if(input_string[i][2] == '*')
            {
                answer += num;
            }
        }
        if(input_string[i][0] == 'x')
            {
                num = 10;
                prize = 3;
            }
        else
            num = (int)(input_string[i][0] - '0');
        if(input_string[i][1] == 'D')
        {
           num = num * num;
        }
        else if(input_string[i][1] == 'T')
        {
            num = num * num * num;
        }
        else
        {
            num = num;
        }
        
        
        if(input_string[i].length() > 2)
        {
            if(input_string[i][prize] == '*')
            {
                num = num*2;
            }
            else if(input_string[i][prize] == '#')
            {
                num = num * (-1);
            }
        }
        answer += num;
        if(prize == 3)
            prize =2;
        
    }
    

        
    
    return answer;
}
