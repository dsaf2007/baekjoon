#include <iostream>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    std::cin >> n;

    std::stack<int> S;
    for(int i = 0; i < n; i++)
    {
        std::string cmd;
        std::cin >> cmd;

        if(cmd == "push")
        {
            int num;
            std::cin >> num;
            S.push(num);
        }
        else if(cmd == "pop")
        {
            if(!S.empty())
            {
                int num = S.top();
                S.pop();
                std::cout << num << "\n"; 
            }
            else
                std::cout << -1 << "\n";
        }
        else if(cmd == "top")
        {
            if(!S.empty())
                std::cout << S.top() << "\n";
            else
                std::cout << -1 << "\n";
        }
        else if(cmd == "size")
        {
            std::cout << S.size() << "\n";
        }
        else if(cmd == "empty")
        {
            if(S.empty())
                std::cout << 1 << "\n";
            else
                std::cout << 0 << "\n";
        }
    }

    return 0;
}