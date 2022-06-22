#include <iostream>
#include <cmath>
int main()
{

    double A, B, V, height;

    std::cin >> A >> B >> V;
    double day = 0;
    height = 0;

    if (A - B == 1)
        day = V - B;
    else
        day = ceil((V - B) / (A - B));

    std::cout << (int)day;
    return 0;
}