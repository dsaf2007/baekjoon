/*
    (a x b)modC = (amodC x bmodC)modC
    모듈러의 성질 이용하여 풀이.
*/
#include <iostream>

long long int power(long long int x, long long int m)
{
    if(m == 0)
    {
        return 1;
    }
    else if(m == 1)
    {
        return x;
    }
    if(m % 2 > 0)
    {
        return power(x, m - 1)*x;
    }
    long long int half = power(x, m/2 );
    half %=c;
    return (half*half)%c;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long int a, b, c;

    std::cin >> a >> b >> c;

    std::cout << power(a,b) %c << "\n";

    return 0;
}