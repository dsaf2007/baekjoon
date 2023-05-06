// #include <iostream>

// int factorial(int n)
// {
//     if(n==0 || n == 1)
//         return 1;

//     return n*factorial(n-1);

// }
// int main()
// {
//     int input;
//     std::cin >>input ;
//     std::cout << factorial(input) << std::endl;
//     return 0;
// }

#include <iostream>

int pactorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        n *pactorial(n - 1);
}

int main()
{

    int input;
    std::cin >> input;
    std::cout << pactorial(n) << std::endl;
    return 0;
}