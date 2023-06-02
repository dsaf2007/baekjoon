// dp 배열에 이전 숫자의 연산 결과를 저장해서 재귀 함수의 중복 연산 회피.
#include <iostream>

int w(int a, int b, int c);

int dp[21][21][21];

int main()
{

    int x, y, z;


    while (1)
    {
        std::cin >> x >> y >> z;
        if (x == -1 && y == -1 && z == -1)
            break;

        std::cout << "w(" << x << ", " << y << ", " << z << ") = " << w(x, y, z) << "\n";
    }

    return 0;
}

int w(int a, int b, int c)
{

    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (dp[a][b][c])
    {
        return dp[a][b][c];
    }
    else
    {
        if (a < b && b < c)
            return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

        else
            return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
}
