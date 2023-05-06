#include <iostream>
#include <deque>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque<int> deq;

    int n;
    cin >> n;

    string cmd; int num;
    for(int i = 0; i < n; i++)
    {
        cin >> cmd;

        if(cmd == "push_front")
        {
            cin >> num;
            deq.push_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >>num;
            deq.push_back(num);
        }
        else if (cmd == "pop_front")
        {
            if(deq.empty())
                cout << -1 << "\n";
            else
            {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        } 
        else if (cmd == "pop_back")
        {
            if(deq.empty())
                cout << -1 << "\n";
            else
            {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }
        else if(cmd == "size")
        {
            cout << deq.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << deq.empty() << "\n";
        }
        else if (cmd == "front")
        {
            if(deq.empty())
                cout << -1 << "\n";
            else
                cout << deq.front() << "\n";
        }
        else if (cmd == "back")
        {
            if(deq.empty())
                cout << -1 << "\n";
            else
                cout << deq.back() << "\n";
        }
    }

    return 0;   
}