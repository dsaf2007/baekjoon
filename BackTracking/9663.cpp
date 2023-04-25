#include <iostream>

int N, result;
int chessBoard[16];


int check(int k)
{
    for(int i = 0; i < k; i++)
    {
        if(chessBoard[i] == chessBoard[k] || k - i == std::abs(chessBoard[k] - chessBoard[i]))
        {
            return false;
        }
    }
    return true;
}

void chess(int k)
{
    if(k == N)
    {
        result++;
        return;
    }
    for(int i = 0; i < N; i++)
    {
        chessBoard[k] = i;
        if(check(k) == true)//놓을 수 있으면
            chess(k + 1);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> N;

    chess(0);    

    std::cout << result << "\n";
    return 0;
}