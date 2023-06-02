#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0));

    int n;
    std::cin >> n;
    int a,b;
    for(int i = 0; i < n; i++)
    {
        std::cin >> a >> b;
        std::cout << "Case #" << i+1 << ": " << a + b << "\n";
    }
    return 0;
}