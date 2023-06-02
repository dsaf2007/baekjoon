#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> v;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        int temp;
        std::cin >>temp;
        v.push_back(temp);
    }
    std::sort(v.begin(), v.end());

    int count = 0;
    int sum = 0;
    for(auto a : v)
    {
        count +=  a;
        sum += count;
    }

    std::cout << sum;
}