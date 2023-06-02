#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        cnt = 0;
        for(int j = 1; j <= 2*n -1; j++)
        {
           if( j > n - i && j < n + i ) std::cout << "*";
           else std::cout << " ";
         }
         std::cout << "\n";
    }
    return 0;
}