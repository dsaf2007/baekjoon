#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int i = 2;
    while(N != 1)
    {
        if( N % i == 0)
        {
            std::cout << i << std::endl;
            N = N/i;
            i--;
        }
        i++;
    }

    return 0;
}