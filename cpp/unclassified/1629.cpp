#include <iostream>

using namespace std;

int a, b ,c;


long long int power(int p)
{
    if(p == 1) return a % c;

    long long int k = power(p/2) % c;

    if(p%2 == 0) return k * k % c;
    else return k*k%c * a%c;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c;

    long long int result = power(b);

    cout << result;

    return 0;
}