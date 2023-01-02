#include <iostream>
#include <vector>

int N, K;
std::vector<int> coin;
int count;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >>temp;
        coin.push_back(temp);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        while(K >= coin[i])
        {
            K -= coin[i];
            count++;
        }
    }

    std::cout << count << std::endl;
}