#include <iostream>
#include <vector>

class Stack
{
private:

    std::vector<int> stack;

public:

    void push(int input)
    {
        stack.push_back(input);
    }
    
    void pop()
    {
        if(stack.size() == 0)
        {
            std::cout << -1 << "\n";
            return;
        }
        std::cout << stack.back() << "\n";
        stack.pop_back();
    }

    void empty()
    {
        if(stack.size() == 0)
        {
            std::cout << 1 <<"\n";
        }
        else
        {
            std::cout << 0 << "\n";
        }
    }

    void size()
    {
        std::cout << stack.size() << "\n";
    }

    void top()
    {
        if(stack.size() == 0)
        {
            std::cout << -1 << "\n";
        }
        else
        {
            std::cout << stack.back() << "\n";
        }
    }


};

int main()
{
    int N;
    std::cin >> N;

    Stack s;
    for(int i = 0; i < N; i++)
    {
        std::string m;
        int a;
        std::cin >> m;
        switch(m)
        {
            case "push":
                std::cin >> a;
                s.push(a);
                break;
            case "pop":
                s.pop();
                break;
            case "size":
                s.size();
                break;
            case "empty":
                s.empty();
                break;
            case "top":
                s.top();
                break;
        }
    }
    return 0;
}