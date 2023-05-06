#include <iostream>

int fi(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fi(n-1)+fi(n-2);
}

int main()
{
    int input;
    std::cin >> input;
    std::cout << fi(input) <<std::endl;

    return 0;
}