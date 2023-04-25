#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::queue<int> q;
    while (n--)
    {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "push")
        {
            int num;
            std::cin >> num;
            q.push(num);
        }
        else if (cmd == "pop")
        {
            if (!q.empty())
            {
                int num = q.front();
                q.pop();
                std::cout << num << "\n";
            }
            else
                std::cout << -1 << "\n";
        }
        else if (cmd == "size")
        {
            std::cout << q.size() << "\n";
        }
        else if (cmd == "empty")
        {
            std::cout << q.empty() << "\n";
        }
        else if (cmd == "front")
        {
            if (!q.empty())
            {
                std::cout << q.front() << "\n";
            }
            else
                std::cout << -1 << "\n";
        }
        else
        {
            if (!q.empty())
            {
                std::cout << q.back() << "\n";
            }
            else
                std::cout << -1 << "\n";
        }
    }
    
    return 0;
}