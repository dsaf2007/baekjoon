// N-Queen 문제

#include <iostream>
#define MAX 15
int N, total;
int chess[MAX];

bool check(int x) //대각선 판정
{
    for (int i = 0; i < x; i++)
    {
        if (chess[x] == chess[i] || abs(chess[x] - chess[i]) == x - i)
            return false;
    }
    return true;
}

void queen(int k)
{
    if (k == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            chess[k] = i;
            if (check(k) == true) // i에 없을 경우
            {
                queen(k + 1);
            }
        }
    }
}

int main()
{

    std::cin >> N;
    bool chess = new bool[N];

    queen(0);

    std::cout << total;
    return 0;
}