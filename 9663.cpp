#include <iostream>

int size;
int* board;
bool* visited;
int cnt;
int N;

bool check(int k)
{
    for(int i = 0; i < k; i++)
    {
        if((board[k] == board[i]) || (k - i == abs(board[k] - board[i])))
            return false;
    }
    return true;
}
void chess(int k)
{
    if(k == N)
    {
        cnt ++;
        return;
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            board[k] = i;
            if(check(k) == true)
                chess(k+1);
        }
    }

}

int main()
{
    std::cin >> N;
    board = new int[N];
    for(int i = 0; i < N; i++)
    {
        board[i] = 0;
    }
    chess(0);
    std::cout << cnt;
    return 0;
}