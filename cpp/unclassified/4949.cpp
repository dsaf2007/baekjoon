#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<string> result;
int main()
{
  
    while(1)
    {
        string input;
        getline(cin, input);
        if(input == ".") break;


        stack<char> s;
        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] == '(' || input[i] =='[')
            {
                s.push(input[i]);
            }
            else if (input[i] == ')' )
            {
                if(!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                else
                    s.push(input[i]);
            }
            else if (input[i] == ']')
            {
                if(!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                else
                    s.push(input[i]);
            }
        }
        if(s.size() == 0)
            result.push_back("yes");
        else
            result.push_back("no");
    }

    for(auto r : result)
    {
        cout << r << "\n";
    }

    return 0;
}