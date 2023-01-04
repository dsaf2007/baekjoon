/*
    이전 가격보다 싼 가격이 나타나면, 더 싼 가격이 나타날 때 까지 주유.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<long long> dist;
std::vector<long long> price;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;
    for(int i = 0; i < N -1; i++)
    {
        long long temp;
        std::cin >> temp;
        dist.push_back(temp);
    }
    for(int i = 0; i < N; i++)
    {
        long long temp;
        std::cin >> temp;
        price.push_back(temp);
    }

    long long tot = 0;
    bool is_min = false;
    long long min_price = price[0];
    for(int i = 0; i < N-1; i ++)
    {
        if(price[i] < min_price)
        {
            min_price = price[i];
        }
        tot += min_price * dist[i];
    } 

    std::cout << tot << "\n";
}