#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> card;
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        int input;
        std::cin >> input;
        card.push_back(input);
    }


    sort(card.begin(),card.end());

    for(int i = N-1; i >=0; i--)
    {
        for(int j = i-1; j>=0;j--)
        {
            for(int k = j-1;k>=0;k--)
            {
                int temp = card[i] + card[j] +card[k];
                if(temp <= M)
                {
                    if(temp > sum)
                    {
                        sum = temp;
                    }
                }
            }
        }
    }
    std::cout << sum;
}